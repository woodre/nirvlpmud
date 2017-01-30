/*
    complex/room.c - generic room
    Feb 1992 by marion@cs.tu-berlin.de
*/

#pragma strong_types            // Coogan, 10-Mar-1999


#include <prop/room.h>          // room properties
#include "/players/data/weather/new/basic/timedep.h"        // time predefines, Coogan, 25-Oct-1997


#define DEFAULT_ITEMS (({ ({ ({ "wall", "walls" }), "ceiling", "floor", }), \
                          ({ "The walls bar your way.\n",                   \
                             "You see nothing special.\n",                  \
                             "The floor spans below your feet.\n" }) }))

#if 0
#define DEBUG_ROOM_RESET
#endif

inherit "/players/data/weather/new/basic/timedepdesc";    // provide time dependant descriptions,
                                // Coogan, 25-Oct-1997
inherit "/players/data/weather/new/basic/description";    // provide short and long description
inherit "/players/data/weather/new/basic/namespace";      // provide namespace for timedep
inherit "/players/data/weather/new/basic/timedep";        // provide time dependant behaviour
inherit "/players/data/weather/new/basic/timedepitem";    // provide time dependant faked items
inherit "/players/data/weather/new/basic/exit";           // provide exits and exit hooks
inherit "/players/data/weather/new/basic/light";          // provide easy light handling
inherit "/players/data/weather/new/basic/extralong";      // provide extra descriptions to our long
inherit "/players/data/weather/new/basic/property";       // provide property values
inherit "/players/data/weather/new/basic/region";         // provide absolute location of the room
inherit "/players/data/weather/new/basic/take_action";    // provide possibility to take fakeitems
inherit "/players/data/weather/new/basic/notify";         // provide ability to notify other objects of
                                // reset in this object
inherit "/players/data/weather/new/basic/autoloading";    // saving of contained auto_load-objects
inherit "/players/data/weather/new/basic/populate";       // provide easy populating, Coogan, 10-Mar-1999
inherit "/players/data/weather/new/basic/view";           // provide view to other rooms Alfe 2002-Jan-17
inherit "/players/data/weather/new/basic/event_listener"; // provide moveevent-listening Alfe 2002-Mar-14
inherit "/players/data/weather/new/basic/traces";         // provide traces in rooms Alfe 2002-Mar-14
inherit "/players/data/weather/new/basic/create";       // Coogan, 10-Mar-1999


// Carador, Feb-1996
varargs void set_short(mixed s, string prep) {
  description::set_short(s);
  remove_property(P_LOCAL_PREPOSITION); // Coogan, 21-Apr-1998
  if (prep)
    set_property(P_LOCAL_PREPOSITION, prep);
}

// Coogan, 24-Oct-1997
varargs void set_long(mixed desc, mixed *depspace) {
  if (depspace || pointerp(desc))
    return timedepdesc::set_long(desc, depspace);
  else
    return description::set_long(desc);
}

#ifdef NEW_LIGHT // Ugh Apr-07-1999
// How much of the daylight is let through by the room
private mixed daylight_factor;

void set_daylight_factor(mixed factor) {
  daylight_factor = factor;
}

// this factor ranges from 0 to 1000
int query_daylight_factor() {
  int factor;
  mixed d;

  if (daylight_factor)
    factor = funcall(daylight_factor);
  else {
  // transform the factor according to local conditions
  // if (query_property(P_FOREST))
  // ...
  // else if (query_property(P_DESERT))
  // ... 
  // added this transformation, Coogan, 01-Jun-1999
    factor = 1000;
    if (!query_property(P_OUTSIDE) && !query_property(P_DAYLIGHT)) {
      factor = 0;  // !
      return factor;
    }
    if (query_property(P_INSIDE)) {                     // inside with daylight
      if (query_property(P_UNDERGROUND))
        factor = (factor * LIGHT_F_UNDERGROUND) / 1000;
      else
        factor = (factor *  LIGHT_F_INSIDE) / 1000;
    } else {                                            // outside
      if (query_property(P_VILLAGE) &&                  // Coogan, 05-Oct-1999
          ((d = SE_TIME->query_day_time()) < 18000 ||   // earlier than 5 a.m.
           d > 72000)) {                                // or later then 8 p.m.
        factor = factor * LIGHT_F_VILLAGE / 1000;       // increase the light
      } else if (d = query_property(P_FOREST)) {
        if (d == TE_LIGHT)
          factor = (factor * LIGHT_F_FOREST_LIGHT) / 1000;
        if (d == TE_NORMAL)
          factor = (factor * LIGHT_F_FOREST_NORMAL) / 1000;
        if (d == TE_DENSE)
          factor = (factor * LIGHT_F_FOREST_DENSE) / 1000;
      } else if (d = query_property(P_DESERT)) {
        if (d == TE_ICE || d == TE_SNOW)
          factor = (factor * LIGHT_F_DESERT_ICE) / 1000;
        if (d == TE_SAND)
          factor = (factor * LIGHT_F_DESERT_SAND) / 1000;
        if (d == TE_ROCK)
          factor = (factor * LIGHT_F_DESERT_ROCK) / 1000;
      } else if (query_property(P_MOUNTAIN)) {     // mountain is ignored,
                                                   // if forest or desert
        factor = (factor * LIGHT_F_MOUNTAIN) / 1000;
      }
      if (query_property(P_UNDER_WATER)) {
        factor = (factor * LIGHT_F_UNDER_WATER) / 1000;
      }
    }
  }
  return 
    factor;
}

// How much light does the room provide
int query_daylight() {
  if (query_property(P_DAYLIGHT) || query_property(P_OUTSIDE))
    return (SE_LIGHT->query_daylight() * query_daylight_factor())/1000;
  return 0;  // Coogan, 27-Mar-2011
}

int set_light(mixed value) {
  if (closurep(value))
    return light::set_light(value);
  light::set_light(value);
  return light::add_light(#'query_daylight);
}
#endif

void configure() {
  "complex/create"::configure();  // Coogan, 10-Mar-1999
  set_short("a non-descript room", "in");
  set_long("You are in a non-descript room.\n");
#ifndef NEW_LIGHT  // Coogan, 10-Mar-1999
  // This must be an ifndef! Otherwise all rooms with P_PLAIN_ROOM
  // will bug, if they are outside ... Coogan.
  set_light(1); // must come first!
#endif
  set_property(P_ROOM);  // Coogan, 12-Apr-2001
  set_traces_count(50);  /* maximal 50 traces are to be stored in this room
                          * Alfe 2002-Mar-14
                          */
}

void save_room() {
  string file;
  if (!(file = query_property(P_SAVE_ROOM)))
    return;
  compute_auto_loading();
  save_object(stringp(file) ? file : "/"+load_name(this_object()));
}

/* load_room - load the room from save-file and clone autoload objects */
void load_room() {
  string file;
  if (!(file = query_property(P_SAVE_ROOM)))
    return;
  restore_object(stringp(file) ? file : "/"+load_name(this_object()));
  load_auto_loading();
}

void refresh() {
  "complex/create"::refresh();
  save_room();
}

void notify_destruct() {
  save_room();
  populate::notify_destruct();  // Coogan, 25-Oct-2002
}

void populate() {
  "complex/create"::populate();
  populate::populate();
}

static varargs void replace_room(string file) { // varargs, Coogan, 09-May-2003
  log_file("/open/replaced.room",
           ctime() + ": " + load_name() + " by " + (file || __FILE__) + "\n");
  replace_program(file || __FILE__);
}

void create() {
  mixed m,h,i;
#ifdef DEBUG_ROOM_RESET
  log_file("DEBUG-room-reset",sprintf("%s: %O: %s\n",ctime(),this_object(),"complex/room::create() ..."),1);
#endif
  "basic/view"::create();  // Alfe 2002-Jan-17
  "complex/create"::create();
#ifdef DEBUG_ROOM_RESET
  log_file("DEBUG-room-reset",sprintf("%s: %O: %s\n",ctime(),this_object(),"... complex/room::create()"),1);
#endif
  // Ugh Jun-08-1995 default items are only added if not already
  // added in configure() and walls, floor and ceiling only in inside rooms
  if (query_property(P_INSIDE)) {
    m = DEFAULT_ITEMS;
    for (i=sizeof(m[0]); i--; )
      if (pointerp(m[0][i]))    /* multiple item with same description ? */
        for (h=sizeof(m[0][i]); h--; ) {
          if (!id(m[0][i][h]))          /* only add if not already added */
            add_item(m[0][i][h], m[1][i]);
        }
      else if (!id(m[0][i]))    /* single item not already added */
        add_item(m[0][i], m[1][i]);
  }

  if (!query_light_closure()) // Coogan, 01-Jun-1999
    set_light(0);

#if 1  // Alfe 2002-Jan-18
  if (query_property(P_OUTSIDE) && (h=SE_AIR->get_air_room(this_object())))
    set_view(h,"in the sky above");
#endif

  if (query_property(P_OUTSIDE) || query_property(P_DAYLIGHT)) {
    if (!id("sky")) {           // only add if not already added
      set_timedep8();
      set_one_item_descriptions("sky",
                                map(TD_DAY8_WHAT,
                                    lambda(({ 'w }),
                                           ({ #'+, "It's ",
                                              ({ #'+, 'w, ".\n" }) }))),
                                TD_DAY8);
    }
    if (!id("moon"))
      add_item("moon", (: LIB_SKY->look_at_sky("moon") :));
    if (!id("sun"))
      add_item("sun", (: LIB_SKY->look_at_sky("sun") :));
    if (!id("star"))
      add_item("star", (: LIB_SKY->look_at_sky("star") :));
    if (!id("stars"))
      add_item("stars", (: LIB_SKY->look_at_sky("stars") :));
  }
  if (m = query_property(P_NOTIFY_LOAD))
    filter_objects(filter(m, lambda(({ 'x }),
                                    ({ #'>,
                                       ({ #'file_size,
                                          ({ #'+, 'x, ".c" }) }), 0 }))),
                   "notify_load", this_object());

  load_room();  // Ugh Jul-26-1996
}

// Coogan, 01-Jun-1999
varargs void set_property(mixed key, mixed value, string item) {
  if (key == P_PLAIN_ROOM
#ifdef NEW_LIGHT
      && !query_light_closure()
       // added the &&-part; this is the most common closure set when
       // a room is loaded. All other closures will bug. Coogan, 02-Oct-2000
#endif
     )
    replace_room(value);  // 'value' added, Coogan, 09-May-2003
  property::set_property(key, value, item);
}

string query_room_long(string str) {
  if (str)
    return funcall(timedepitem::query_long(str));
  return (funcall(timedepdesc::query_composite_long() ||
                  description::query_long()) || "" ) +
         extralong::query_long();// timedepdesc stuff added, Coogan, 24-Oct-1997
}

// removed 'private' modifier, Coogan, 22-Mar-1998
string query_darkness() {
  return ({ "You can't see anything.\n",
            "It is too dark to see.\n",
            "Darkness engulfs you.\n",
            "You stare into impenetrable darkness.\n",
            "It is pitch dark.\n" }) [random(5)];
}

string query_long(string str) {
  string result;
  if (light() <= 0)
    return query_darkness();
  result = query_room_long(str);
  if (result)
    // added !! to the calls of query_exit_long(), Coogan, 26-Sep-2010 
    return result + (str ? "" : query_exit_long(!!str));
  if (!str)
    return query_exit_long(!!str); /* changed by Ugh 08-Jul-1994 */
  return 0;  // Coogan, 28-Mar-2011
}

string query_short() {
  return funcall(description::query_short());
}

void init() {
  exit::init();
  timedepitem::init();
  
  // turn entering invisible players visible if the room so chooses
  // (wizards are exempt), Chameloid, 03-Nov-1998
  
  if (query_property(P_NO_INVISIBILITY) && this_player())
    if (!is_wizard(this_player(), IW_APPRENTICE) &&
        !is_wizard(this_player(), IW_TOOLUSER) &&
        !this_player()->short()) {
      write("Due to the local interferences you turn visible again.\n");
      this_player()->vis(1); // silently
    }
}

int clean_up(int arg) {
  if (first_inventory(this_object()) ||
      clonep() || arg > 1)  // changed arg >= 1 zu clonep() and >, because
                            // otherwise replaced objects are never cleaned up.
                            // Coogan, 07-Jun-1999
    return 0;
  if (query_property(P_NO_CLEANUP))
    return 0;
  if (!populate::test_clean_up(arg))  // Coogan, 30-Oct-1999
    return 0;
  remove();
  return 0;  // Coogan, 24-Mar-2011
}

int insert_objects() {
  return 1;
}

int add_encumbrance(int add) {
  return 1;
}

int add_weight(int add) {
  return 1;
}

void reset(int arg) {  // changed to complex/create, Coogan, 10-Mar-1999
#ifdef DEBUG_ROOM_RESET
  log_file("DEBUG-room-reset",sprintf("%s: %O: %s\n",ctime(),this_object(),"complex/room::reset("+arg+") ..."),1);
#endif
  "complex/create"::reset(arg);
  /* load additional objects after the normal configuration and population */
  /* added by Ugh May-23-1995 */
  notify::reset(arg);
#ifdef DEBUG_ROOM_RESET
  log_file("DEBUG-room-reset",sprintf("%s: %O: %s\n",ctime(),this_object(),"... complex/room::reset("+arg+")"),1);
#endif
}

void notify_sun(string sun_state) {
  string msg;
  if ((msg = LIB_LIGHT->get_notify_sun_message(sun_state)))
    tell_room(this_object(), msg);
}

private string air_room;

void set_air_room(string room) {  // Alfe 2001-Jul-11
  air_room = room;
}

string query_air_room() {  // Alfe 2001-Jul-11
  return air_room;
}

/*
 * trace functionality
 */

void notice_move_event(mapping e, string t, int p) {
  object agent, *boots, boot;
  mixed *trace;
  agent = e[E_AGENT];
  boots = filter(agent->query_armour() || ({}),
                 (: $1 && $1->query_type() == "boot" :));
  if (sizeof(boots))
    boot = boots[0];  // take first boot-type armour which is worn
  else
    boot = 0;
  trace = ({ 0,  // will be filled next
             agent->query_real_name() || agent->query_name(),
             e[E_DIR], boot && (boot->query_laid_trace() ||
                                describe(boot, 0, 1) ||
                                boot) });
  if (e[E_FROM] == this_object()) {
    trace[0] = "leave";
    lay_trace(trace[0..]);
  }
  if (e[E_TO] == this_object()) {  // not 'else if' because both might be!
    trace[0] = "enter";
    lay_trace(trace);
  }
  if (!trace[0])
    raise_error("Bad call of notice_move_event()\n");
}

// Coogan, 08-May-2002
int apply_action(string action, int level, mapping args) {
  return 0;
}

