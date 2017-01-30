/*****************************************************************************
              bodypart.c -- a basic bodypart for complex bodies
                        written by Ugh for Tubmud 1997
******************************************************************************/

#include <combat.h>
#include <assert.h>

inherit "basic/race";           // so we can be identified
inherit "basic/type";           // what kind of bodypart are we
inherit "basic/position";       // where do we find ourselves in the body
inherit "basic/woundable";      // so we can be damaged and wounded
inherit "basic/hittable";       // hit locations
inherit "basic/wear";           // so we can wear something
inherit "basic/component";

// this is needed by /basic/wear
string query_real_name() { return get_component_name(); }

/*************************** Bodypart-Data **********************************/

void set_bodypart_data(string data_type, mixed data);
void remove_bodypart_data(string data_type);
varargs mixed get_bodypart_data(string data_type);
status has_bodypart_data(string data_type);

private static mapping bodypart_data;

void set_bodypart_data(string data_type, mixed data) {
  set_component_data(data,data_type);
}

void add_bodypart_data(string data_type, mixed data) {
  mixed h;
  h = get_bodypart_data(data_type);
  if (!h)
    h = ({ data });
  else
    h += ({ data });  // it is ok that this will raise an error if h isn't
                      // an array but not 0 either.
  set_bodypart_data(data_type,h);
}

void subtract_bodypart_data(string data_type, mixed data) {
  mixed h;
  h = get_bodypart_data(data_type);
  if (!h)
    h = ({});
  else
    h -= ({ data });  // it is ok that this will raise an error if h isn't
                      // an array but not 0 either.
  set_bodypart_data(data_type,h);
}

void remove_bodypart_data(string data_type) {
  remove_component_data(data_type);
}

// varargs because get_component_data() is varargs, Coogan, 27-Sep-2010
varargs mixed get_bodypart_data(string data_type) {
  return get_component_data(data_type);
}

status has_bodypart_data(string data_type) {
  return has_component_data(data_type);
}

/******************************** Resources *********************************/
/*
  This part of the code is responsible for 'locking' bodyparts for use of
  different actions (e.g. an arm for a punch, a leg for a kick, a head for
  a spell etc.) or sharing them with other actions (the other leg for
  a kick while standing)
*/

void set_compound_bodypart(object p) {
  set_compound(p);
}

object get_compound_bodypart() {
  return get_compound();
}

private static mixed used;
private static mapping shared;
private int activation = 1;  // activation > 0 => active

status query_active_bodypart();
varargs status deactivate_bodypart(mapping marked);
varargs status activate_bodypart(mapping marked);

varargs mixed query_used_bodypart(mixed by);
varargs mixed query_shared_bodypart(mixed by);
status query_free_bodypart();

status can_use_bodypart(mixed by);
status can_share_bodypart(mixed by);
status can_free_bodypart(mixed by);

void use_bodypart(mixed by);
void share_bodypart(mixed by);
void free_bodypart(mixed by);

// all objects which have told us that they want to be notified when we
// are freed or activated again or if we are deactivated.
private static object *waiting;

// returns whether the given object is one that wants to be notified when
// we are freed or activated again or if we are deactivated.
status query_waiting_for_bodypart(object ob) {
  return waiting && member(waiting,ob) >= 0;
}

object *get_waiting_for_bodypart() {
  return waiting;
}

// this will set the given object as one that wants to be notified when we
// are freed or activated again or if we are deactivated.
varargs // this is only because of an inheritance bug
void wait_for_bodypart(object ob) {
  assert(objectp(ob));
  if (!waiting)
    waiting = ({});
  // We can only wait 'once' for a bodypart
  if (!query_waiting_for_bodypart(ob))
    waiting += ({ob});
}

// this is called when the given object does not want to be notified by us
// any longer.
varargs // this is only because of an inheritance bug
void stop_waiting_for_bodypart(object ob) {
  if (waiting && sizeof(waiting))
    waiting -= ({ob});
}

// this function notifies all waiting objects about a change of our state
// like freed, deactivated or activated.
// reason is either BP_FREED, BP_DEACTIVATED or BP_ACTIVATED
private void notify_waiting(mixed reason) {
  int i;
  object *obs;

  // this must not be done in a for loop using an index variable which simply
  // calls all waiting objects because the global variable 'waiting' can
  // possibly be changed by one of the call_others() (indirectly).
  if (waiting && (reason == BP_DEACTIVATED || query_free_bodypart())) {
    obs = waiting[0..];
    waiting = ({});
    for (i = sizeof(obs); i && query_free_bodypart(); i--)
      if (obs[<i])
        obs[<i]->notify_awaited_bodypart(reason,this_object());
    // the rest is still waiting
    waiting = obs[<i..]+waiting;
  }
}

string *get_connected_bodyparts();
string *get_depending_bodyparts();

status query_active_bodypart() {
  return activation > 0;
}

varargs status activate_bodypart(mapping marked) {
  int i;
  mixed h;
  status activated;

  if (!marked)
    marked = ([ this_object() ]);
  else if (member(marked,this_object()))
    return 0;
  else
    marked += ([ this_object() ]);
  // activate ourself
  activated = ++activation == 1;

  // activate the depending bodyparts of the same level
  map(get_depending_bodyparts(),#'call_component,
            "activate_bodypart",marked);

  if (h = get_compound_bodypart())
    h->activate_component_bodypart(this_object(),marked);

  if (activated) { // we have just become active
    // notify waiting objects only, if we are active now
    notify_waiting(BP_ACTIVATED);
    return 1;
  }
}

varargs status deactivate_bodypart(mapping marked) {
  int i;
  mixed h;
  status deactivated;

  if (!marked)
    marked = ([ this_object() ]);
  else if (member(marked,this_object()))
    return 0;
  else
    marked += ([ this_object() ]);
  deactivated = --activation == 0;

  map(get_depending_bodyparts(),#'call_component,
            "deactivate_bodypart", marked);

  if (h = get_compound_bodypart())
    h->deactivate_component_bodypart(this_object(),marked);

  // notify waiting objects only if we are inactive now
  if (deactivated) { // we have just become inactive
    // notify all objects that are waiting for us
    notify_waiting(BP_DEACTIVATED);
    if (h = query_used_bodypart())
      // notify the object that is using us
      h->notify_deactivate_bodypart(this_object());
    else if (h = query_shared_bodypart())
      // notify the objects that share us
      map_objects(h,"notify_deactivate_bodypart",this_object());
    return 1;
  }
}

varargs mixed query_used_bodypart(mixed by) {
  return
    used && (by ? used == by : used);
}

varargs mixed query_shared_bodypart(mixed by) {
  return
    shared && sizeof(m_delete(shared,0)) &&
    (by ? member(shared, by) : m_indices(shared));
}

status query_free_bodypart() {
  return !(query_used_bodypart() || query_shared_bodypart());
}

status can_use_bodypart(mixed by) {
  return
    query_active_bodypart() &&
    query_free_bodypart();
}

status can_share_bodypart(mixed by) {
  return
    query_active_bodypart() &&
    !query_used_bodypart();
}

status can_free_bodypart(mixed by) {
  return
    query_shared_bodypart(by) ||
    query_used_bodypart(by);
}

void use_bodypart(mixed by) {
  used = by;
}

void share_bodypart(mixed by) {
  if (!shared)
    shared = ([by]);
  else
    shared += ([by]);
}

void free_bodypart(mixed by) {
  if (!by)
    raise_error("Bad argument 1 to lfun free_bodypart()\n");
  if (query_shared_bodypart(by))
    shared -= ([by]);
  else if (query_used_bodypart(by))
    used = 0;
  else
    return;
  notify_waiting(BP_FREED);
}

/**************************** Connections **********************************/
//---------------------------------------------------------------------------
// This part concerns itself with the information, to which other bodyparts
// this one is connected and which we are depending on.
// Being depending on another bodypart means, that, if that part is
// deactivated (due to loss of health, for instance), we're deactivated, too.
// For that, a level of 'activation' is also being kept.
// The current implementation is such, that per default, the bodypart is
// active, as long as there is a bodypart on which it depends, that is still
// active, or if it doesn't depend on any other bodyparts.
// Thus, a torso with two heads is still active, even after one of the heads
// has been deactivated.
//---------------------------------------------------------------------------
private mapping connectors;
private mapping connections; // mapping bodyparts -> (dependence x location)

varargs status query_connected_to_bodypart(mixed part, string at);
                                        // changed to mixed, Coogan, 18-Oct-2000
string *get_connected_bodyparts();
status query_depending_bodypart(string part); // changed from (object of);
                                        // Coogan, 18-Oct-2000
string *get_depending_bodyparts();

void disconnect_from_bodypart(object part);
void connect_with_bodypart(object part, string at, string at2,
                           status depending);

void add_bodypart_connectors(string *c) {
  if (!connectors)
    connectors = ([]);
  connectors += mkmapping(c);
}

string *get_bodypart_connectors() {
  return connectors ? m_indices(connectors)-({0}) : ({});
}

status query_depending_bodypart(string part) {
  return
    connections &&
    // return true if we're not depending on it
    // because then, it depends upon us, apparently
    !connections[part];
}

string *get_depending_bodyparts() {
  return
    filter(get_connected_bodyparts(), #'query_depending_bodypart);
}

varargs status query_connected_to_bodypart(mixed part, string at) {
  if (objectp(part))
    part = part->get_component_name();
  if (!at)
    return connections && member(connections,part);
  else
    return connections && connections[part,1] == at;
}

string *get_connected_bodyparts() {
  return connections ? m_indices(connections) : ({});
}

void disconnect_from_bodypart(object part) {
  if (!connections)
    return;
  m_delete(connections,objectp(part) ? part->get_component_name() : part);
}

void connect_with_bodypart(object part, string at, string at2,
                           status depending) {
  if (!connections)
    connections = ([]);
  connections += ([ part->get_component_name() : depending; at2; at ]);
  if (!depending)
    part->connect_with_bodypart(this_object(),at2,at,1);
}

/****************************** Size ****************************************/

void set_size(int size);
int get_size();
void set_toughness(int toughness);
int get_toughness();

int get_size() {
  return get_bodypart_data(BT_SIZE);
}

void set_size(int size) {
  return set_bodypart_data(BT_SIZE,size);
}

int query_toughness() {
  return get_bodypart_data(BT_TOUGHNESS);
}

void set_toughness(int toughness) {
  return set_bodypart_data(BT_TOUGHNESS,toughness);
}

/****************************** Health **************************************/

int set_health(int amount);  // changed to int, Coogan, 18-Oct-2000
int get_health();
int heal_bodypart(int amount);
int damage_bodypart(int amount);

int get_max_health() {
  // Return some value depending on a formula depending on the size
  // and the Constitution
  return 0;  // Coogan, 26-Mar-2011
}

int get_health() {
  return get_bodypart_data(BT_HEALTH);
}

int set_health(int health) {
  mixed h;

  if (health > (h = get_max_health()))
    health = h;
  set_bodypart_data(BT_HEALTH,h);
  return h;
}

int heal_bodypart(int amount) {
  if (amount < 0)
    return get_health();
  return
    set_health(get_health()+amount);
}

int damage_bodypart(int amount) {
  if (amount < 0)
    return get_health();
  return
    set_health(get_health()-amount);
}

/****************************** User/owner **********************************/

private static object user;

void
set_user(object u)
{
  user = u;
}

object
get_user()
{
  return user;
}

void modify_damage(mapping d) {
  int i;
  object *worn;

  worn = get_wearing();
  // Since every armour is put at the end, let them modify from 'outside'
  // which for this loop means: from the end of the array
  // Every armour can put itself into the damage-mapping and thus 'absorb'
  // some of the damage meant for this bodypart
  for (i = sizeof(worn); i--; )
    worn[i]->modify_damage(d);
}

/*************************** Saved data of component ************************/

mixed get_component_state() {
  return
    (["bodypart_data" : get_bodypart_data(),
      "position"      : query_position(),
      "activation"    : activation ]);
}

set_component_state(mixed state) {
  set_bodypart_data(state["bodypart_data"]);
  set_position(state["position"]);
  activation = state["activation"];
}
