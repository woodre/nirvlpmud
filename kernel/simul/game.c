/*
 * kernel/simul/game.c
 *
 * simul_efuns concerning game matters.
 * Rumplemintz
 */

#pragma strong_types

#include "/kernel/support/name.h"
#include "/kernel/simul/lpc.h"
#if 0
#include "/kernel/simul/file.h"
#endif
#include "/kernel/simul/message.h"
#include "/kernel/simul/string.h"
#include "/kernel/simul/array.h"

#include <accessible.h>
#include <inventory.h>
#include <stack.h>
#include <kernel.h>
#include <is_wizard.h>
#include <wizlevels.h>
#include <fingerd.h>
#include <ctype.h>
#include <server.h>
#include <prop/room.h>
#include <prop/player.h>
#include <prop/item.h>
#include <libs.h>
#include <perceivable.h>

int perceivable(mapping event, object living) {
  // this function contains intelligence determining whether the given living
  // can perceive the given event.  The return value is a bitmask of the bits
  // named in <perceivable.h> for the various senses.
  return PERCEIVE_ALL;  // not implemented yet.
}

int get_encumbrance(object o) {
  if (!objectp(o))
    raise_error("Bad argument 1 to get_encumbrance()\n");
  return o->query_encumbrance() || 2500 * o->query_weight();
}

int get_mass(object o) {
  if (!objectp(o))
    raise_error("Bad argument 1 to get_mass()\n");
  return o->query_mass() || get_encumbrance(o);
}

int get_area_size(object o) {
  int a;
  if (!objectp(o))
    raise_error("Bad argument 1 to get_area_size()\n");
  if ((a = o->query_property(P_AREA_SIZE)) ||
      (a = o->query_area_size()))
    return a;
  if (o->id("fur") || o->id("skin"))
    return LIB_RACE->get_area_size(o);
  return get_encumbrance(o)/10;
}

private closure shout_each;

void shout(string s) {
  shout_each = shout_each ||
               lambda(({ 'o,'s }),
                      ({ #'&&,
                         ({ #'environment,'o }),
                         ({ #'!=,'o,({ #'this_player }) }),
                         ({ #'simul_efun_call, "tell_object",'o,'s }) }));
  filter(filter(users(),(: load_name($1) != "obj/login" :)),
         shout_each, s);
}


int query_is_wizard(object player) {
#if 0
  return set_is_wizard(player,-1);
#else
  return player->query_level() > 19;
#endif
}

#if 1 // Use this version until new security is in place
varargs status is_wizard(mixed who, int mode) {
  switch (mode) {
  case IW_WIZARD:
  case 0: // default
    if (objectp(who))
      return (query_once_interactive(who) &&
              (who->query_level() > WL_WIZARD));
    return 0;
  case IW_APPRENTICE:
    if (objectp(who))
      return ((query_once_interactive(who) &&
               (who->query_level() >= WL_APPRENTICE)) ||
              is_wizard(who, IW_WIZARD));
    return 0;
  case IW_TESTPLAYER:
    if (objectp(who))
      return (query_once_interactive(who) &&
              (who->is_testchar() || is_wizard(who, IW_WIZARD)));
    return 0;
  case IW_TOOLUSER:
    if (objectp(who))
      return (query_once_interactive(who) &&
              (who->query_level() >= WL_MENTOR_WIZ));
    return 0;
  default:
    raise_error("Bad argument 2 to is_wizard()\n");
  }
  NO_WARN_MISSING_RETURN;
}
#else
varargs status is_wizard(mixed who,int mode) {
  mixed temp;
  switch (mode) {
  case IW_WIZARD:
  case 0:  // default
    if (objectp(who)) {
      temp = query_once_interactive(who) && who->query_privilege();
      if (intp(temp))
        return temp;
    }
    else if (stringp(who))
      temp = who;
    else
      return 0;
    return SECURITY->query_is_wizard(temp) && 1;
  case IW_APPRENTICE:
    if (objectp(who))
      return ((query_once_interactive(who) &&
               (who->query_level() >= WL_APPRENTICE)) ||
              is_wizard(who,IW_WIZARD));
    if (!stringp(who))
      return 0;
    if (temp = FINGERD->load_player(who))
      return (temp->query_level() >= WL_APPRENTICE ||
              SECURITY->query_is_wizard(who));
    return 0;
  case IW_TESTPLAYER:
  case IW_TOOLUSER:
    if (objectp(who))
      return (query_once_interactive(who) &&
              (who->query_property(P_TESTPLAYER) ||
               who->test_flag(96) ||
               is_wizard(who,IW_WIZARD)));
    if (!stringp(who))
      return 0;
    if (temp = FINGERD->load_player(who))
      return (temp->query_property(P_TESTPLAYER) ||
              temp->test_flag(96) ||
              SECURITY->query_is_wizard(who));
    return 0;
  default:
    raise_error("Bad argument 2 to is_wizard()\n");
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 24-Mar-2011
}
#endif

/*
void wizlist(mixed arg) {
  "/global/wizlist"->show_wizlist(arg);
}
*/

/*
 * get_location()
 * return the location of the object, that is, the room where the object
 * is located.
 */
object get_location(object ob) {
  object env, h;

  env = environment(ob);
  while (h = env)
    if (h->query_property(P_ROOM) ||
        !(env = environment(h)))
      return h;
  return 0;
}

private closure move_inv;

/*
 * Function name:   update_actions
 * Description:     Updates this_object's actions in all living objects
 */
varargs void update_actions(object ob) {
  ob = ob || previous_object();
  if (environment(ob))
    efun::move_object(ob,environment(ob));
  move_inv =
    move_inv || 
    lambda(({ 'ob,'where }),
           ({ (#'&&),
              ({ (#'living),'ob }),
              ({ (#'efun::move_object),'ob,'where }) }));
  filter(turn_array(all_inventory(ob)),move_inv,ob);
}

object present_clone(mixed file, mixed ob) {
  if (objectp(ob))
    return efun::present_clone(file, ob);
  if (!stringp(ob))
    raise_error("Bad argument 2 to present_clone()\n");
  ob = load_object(ob);
  return efun::present_clone(file, ob);
}

object present_property(mixed prop, mixed ob) {
  if (stringp(ob))
    ob = load_object(ob);
  else if (!objectp(ob))
    raise_error("Bad argument 2 to present_property()\n");
  for (ob = first_inventory(ob); ob; ob = next_inventory(ob))
    if (ob->query_property(prop))
      return ob;
  return 0;
}

#ifndef NEW_LIGHT
int query_light(object ob) {
    closure light;
    light = unbound_lambda(0,({ #'set_light, 0 }));
    return funcall(bind_lambda(light,ob));
}
#endif

varargs mixed with_player(object player,closure code,mixed args) {
  object old_player;
  mixed result;
  if (!player)
    player = load_object("etc/console");
  if (player == (old_player = this_player()))
    return apply(code,args);
  efun::set_this_player(player);
  result = apply(code,args);
  if (old_player)
    efun::set_this_player(old_player);
  return result;
}

/*
 * accessible() returns a true value, if an object is 'there' for
 * another object (e.g. if it is its environment, in its environment,
 * in its inventory, in a container in its environment/inventory).
 */
varargs status accessible(object ob,object to,string container_id,int flags) {
  object env_ob, env_to;
  env_ob = ENVIRONMENT(ob);
  env_to = ENVIRONMENT(to);
  // 'ob' is the environment of 'to'
  if (env_to == ob /* present(to,ob) */) 
    return !(flags & (A_NO_ROOM|A_GET));
  if ((flags & A_SEE) && !with_player(to,#'call_other,({ob,"short"})))
    return 0;
  // 'to' is the environment of 'ob'
  if (env_ob == to /* present(ob,to) */)
    return !(flags & A_NO_INVENTORY);
  if (env_ob == env_to /* environment(ob) == environment(to) */) {
    if ((flags & A_GET) && 
        // can't get yourself or things for which ob->get() returns 0
        (to == ob || !with_player(to,#'call_other,({ob,"get"}))))
      return 0;
    return !(flags & A_NO_ENVIRONMENT);
  }
  // it must be in a container somewhere 
  if (flags & A_NO_CONTAINER)
    return 0;
  if ((!(flags & A_NO_INVENTORY) && env_ob /* environment(ob) */ && 
        environment(env_ob) == to /* present(environment(ob),to) */) ||
      (!(flags & A_NO_ENVIRONMENT) && 
       env_ob /* environment(ob) && environment(to) */ &&
       environment(env_ob) == env_to 
       /* present(environment(ob),environment(to)) */)) {
    if ((flags & A_GET) && !with_player(to,#'call_other,({ob,"get"})))
      return 0;
    if (flags & A_ONLY_LOOKING)
      return 
        !with_player(to, #'call_other, 
                    ({env_ob /* environment(ob) */,
                      "hide_inventory", container_id}));
    else
      return 
        with_player(to, #'call_other, 
                    ({env_ob /* environment(ob) */,
                      "can_put_and_get", container_id}));
  }
  return ob->query_accessible(to, container_id, flags);
}

void empty_notify_fail() {
  efun::notify_fail("");
}

#if 0
nomask varargs int notify_fail(mixed message,varargs mixed prio) {
  object envtp,envpo,o;

  if (!this_player())
    return 0;
  switch (sizeof(prio)) {
  case 0:  // nothing given, use a default priority for this case
    if (previous_object() == this_player()) {
      prio = -1;  // we _are_ the player
      break;
    }
    for (o=previous_object(); o; o=environment(o)) {
      envpo = o;
      if (o == this_player()) {
        prio = 0;  // we are _in_ the player (carried by him)
        break;  // by the following 'if' we also break out of the switch ...
      }
    }
    if (intp(prio))  // grmpf. no goto. >:-(
      break;
    // now: compute the outmost environment of previous_object and this_player
    while (o=environment(envpo))
      envpo = o;
    for (o=environment(this_player()); o; o=environment(o))
      envtp = o;
    if (envtp == envpo) {
      prio = 1;  // we are somewhere _at_ the player (part of the room)
      break;
    }
    prio = -1;  // we are not present, a daemon or something
    break;
  case 1:  // one argument given, normal case
    prio = prio[0];
    break;
  default:  // more than one?! error
    raise_error("Too many arguments to notify_fail()\n");
  }
  if (stringp(message) || pointerp(message) || closurep(message))
    this_player()->set_notify_fail(message,prio);
  else
    raise_error("Bad argument 1 to notify_fail()\n");
  return 0;
}
#endif

private string verb;

// Only in case of nested calls of command() (or a command()-call caused
// by typed input), it can happen that efun::query_verb() is set to 0,
// since efun::command() does not restore the old verb (of the upper
// command()-call. For this case, we do so.
nomask string query_verb() {
  return efun::query_verb() || verb;
}

// This function should be called by people who make a catch() around
// a statement that causes command() to be called
// Before doing so, they should store the current query_verb() somewhere,
// and if an error occured in the catch()-statement (i.e. catch() returned
// an error-string), set_verb() should be called with the old verb.
// This function has no effect inside a functioning command()-call,
// since the efun::query_verb() always takes precedence before the
// verb stored by simul_efun.
// This function only changes the stored verb, if efun::query_verb() returns 0
nomask void set_verb(string v) {
  string old_verb;

  old_verb = verb;
  verb = 0;
  if (!query_verb())
    verb = v;
  else // we don't need the given verb.
    verb = old_verb;
}

/*
nomask varargs int command(string comm, object who, status without_alias) {
  mixed result;
  string old_verb;

  if (!stringp(comm))
    raise_error("Bad argument 1 to command()\n");
  if (!(objectp(who) || (who = previous_object())))
    raise_error("Bad or missing argument 2 to command()\n");
  if (!intp(without_alias))
    raise_error("Bad argument 3 to command()\n");
  if (who && query_once_interactive(who) && this_interactive() &&
      load_name(this_interactive()) != "obj/login" &&  // relogin
      this_interactive () != who
       && comm != "look" && comm != "see" && comm != "glimpse"
      )
    log_file("COMMAND",
             ctime(time()) + " " + this_interactive()->query_vis_name() +
             " forced " + who->query_vis_name() + " to " + comm +
             " (in object: " + object_name(previous_object()) +
             " commandline: " + (this_interactive()->query_commandline() ||
                                 query_verb()) + ")\n");
  // if it is a non-interactive-living, try to let it modify the command, too
  if (!query_once_interactive(who))
    // if modify_command() didn't return a string (or 0), then the result 
    // should be returned as the result of command()
    if (!stringp(result = who->modify_command(comm) || comm))
      return result;
    else
      comm = result;
  // First, remember the old current verb
  old_verb = query_verb();
  // escape the command with prepended '\', if the forced living is a player
  if (without_alias && query_once_interactive(who))
    comm = "\\"+comm;
  // now, get the result of the command()
  result = efun::command(comm,who);
  // reset the verb to the old_verb afterwards 
  set_verb(old_verb);
  return result;
}
*/

// -- a command() which computes the command from a message first
varargs int message_command(mixed mess,object who,mapping args) {
  if (!who)
    who = previous_object();
  if (stringp(mess))
    return command(mprintf(mess,args),who);
  else
    return command(message2string(mess,who,args),who);
}

#if 0
mapping living_name_m, name_living_m;

static void clean_name_living_m(string *lkeys, int left) {
  int i, j;
  mixed a;
  
  if (left) {
    if (pointerp(a = name_living_m[lkeys[--left]]) && member(a, 0)) {
      i = sizeof(a);
      do {
        if (a[--i])
          a[<++j] = a[i];
      } while (i);
      name_living_m[lkeys[left]] = a = j > 1 ? a[<j..] : a[<1];
    }
    if (!a)
      m_delete(name_living_m, lkeys[left]);
    efun::call_out("clean_name_living_m", 1, lkeys, left);
  }
}

static void clean_simul_efun() {
  /* There might be destructed objects as keys. */
  m_indices(living_name_m);
  remove_call_out("clean_simul_efun");
  if (find_call_out("clean_name_living_m") < 0)
    efun::call_out("clean_name_living_m", 2,
                   m_indices(name_living_m),
                   sizeof(name_living_m));
  efun::call_out("clean_simul_efun", 3600);
}

#define IGNORE_CASE_IN_LIVING_NAMES

nomask
void set_living_name(string name) {
  string old;
  mixed a;
  int i;
#ifdef IGNORE_CASE_IN_LIVING_NAMES
  name = lower_case(name);
#endif
  if (old = living_name_m[previous_object()]) {
    if (pointerp(a = name_living_m[old]))
      a[member(a, previous_object())] = 0;
    else
      m_delete(name_living_m, old);
  }
  living_name_m[previous_object()] = name;
  if (a = name_living_m[name]) {
    if (!pointerp(a)) {
      name_living_m[name] = ({a, previous_object()});
      return;
    }
    /* Try to reallocate entry from destructed object */
    if ((i = member(a, 0)) >= 0) {
      a[i] = previous_object();
      return;
    }
    name_living_m[name] = a + ({previous_object()});
    return;
  }
  name_living_m[name] = previous_object();
}

object find_exact_living(string name) {
  mixed *a, r;
  int i;
#ifdef IGNORE_CASE_IN_LIVING_NAMES
  name = lower_case(name);
#endif
  if (pointerp(r = name_living_m[name])) {
    if (!living(r = (a = r)[0]))
      for (i = sizeof(a); --i;)
        if (living(a[<i])) {
          r = a[<i];
          a[<i] = a[0];
          return a[0] = r;
        }
    return r;
  }
  return living(r) && r;
}

mixed find_all_livings(string name) {
  mixed h;
#ifdef IGNORE_CASE_IN_LIVING_NAMES
  name = lower_case(name);
#endif
  h=name_living_m[name];
  return (h? (pointerp(h)? h[0..] : ({ h })) : ({}));
}

object find_living(string name) {
#ifdef IGNORE_CASE_IN_LIVING_NAMES
  name = lower_case(name);
#endif
  return find_exact_living(name) || find_exact_living(to_real_name(name));
}

object find_player(string name) {
  mixed *a, r;
  int i;
  if (pointerp(r = name_living_m[to_real_name(name)])) {
    if ( !(r = (a = r)[0]) || !query_once_interactive(r)) {
      for (i = sizeof(a); --i;)
        if (a[<i] && query_once_interactive(a[<i])) {
          r = a[<i];
          a[<i] = a[0];
          return a[0] = r;
        }
      return 0;
    }
    return r;
  }
  return r && query_once_interactive(r) && r;
}

/*
 * the following efun returns the living containing the given object.
 * If the object itself is a living, this object is returned. If there is
 * no containing living, 0 is returned.
 */
varargs object find_living_environment(object ob) {
  if (!ob)
    ob = previous_object();
  return funcall(
        lambda(({ 'f, 'x }), ({ #'funcall, 'f, 'f, 'x })),
        lambda(({ 'g, 'y }),
               ({ #'?, 'y,
                  ({ #'?, ({ #'living, 'y }),
                          'y,
                     ({ #'funcall, 'g, 'g,
                        ({ #'environment, 'y }) }) }),
                  0 })),
        ob);
}
#endif

/*
void start_simul_efun() {
  living_name_m = alloc_wl_entry("living->name");
  name_living_m = alloc_wl_entry("name->living");
  if (find_call_out("clean_simul_efun") < 0)
    efun::call_out("clean_simul_efun", 1800);
}
*/

// this function should return the castle-file of the given creator
// or the creator of the given object
string castle_file(mixed ob_or_creator) {
  if (objectp(ob_or_creator))
    ob_or_creator = creator(ob_or_creator);
  else if (!(stringp(ob_or_creator) &&
        valid_name(regreplace(ob_or_creator,"_","",1))
        ))
    raise_error("Bad argument 1 to castle_file()\n");
  if (stringp(ob_or_creator) && strlen(ob_or_creator)) {
    if (isupper(ob_or_creator[0]))
      return "/domains/"+lower_case(ob_or_creator)+"/castle.c";
    else
      return "/players/"+ob_or_creator+"/castle.c";
  }
}

object get_room(object obj) {
  object env, o;
  o = environment(obj);
  while (o && !o->query_property(P_ROOM) &&
         (env=environment(o)))
    o = env;
  return o || obj;
}

