/*
 * complex/door.c (C) Ugh Nov-1994, written for Tubmud
 *
 */

#pragma strong_types

#include <grammar.h>
#include <describe.h>
#include <event.h>
#include <prop/item.h>
#include <message.h>
#include <server.h>

#define CANCEL_PRIO 300
#define NO_PARTNER  -1 /* must be true */

inherit "basic/lockable";
inherit "complex/exit";


private mixed door_long, door_short;

private mixed listen_open_text, 
              listen_close_text, 
              listen_lock_text, 
              listen_unlock_text,
              knock_text,
              listen_knock_text,
              not_open_text; 

private mixed default_open, // = 0, Alfe 2001-Oct-16; mixed, Coogan, 21-Nov-2001
              default_locked; 
private status update_on_reset = 1, // per default it should update itself
               new = 1,             // a door, if cloned, is new
               open_direction = 1,  // it can move in this direction per default
               remove_exit_on_destruct = 1,
               remove_partner_on_destruct;

private string *wind_dirs = ({  "north",
                                "south",
                                "east",
                                "west",
                                "northeast",
                                "northwest",
                                "southeast",
                                "southwest",
                            }); /* this is more effective
                                    than generating it when needed */

private string *pointing = ({ "going", "leading", "towards" });

void init_door();

void set_default_open(mixed open);
void set_default_locked(mixed locked);
void set_open_direction(status here);
void set_remove_exit_on_destruct(status state);
void set_remove_partner_on_destruct(status state);
status query_open_direction();

void set_listen_open_text(mixed text);
void set_listen_close_text(mixed text);
void set_listen_lock_text(mixed text);
void set_listen_unlock_text(mixed text);

varargs mixed query_listen_open_text(mapping args);
varargs mixed query_listen_close_text(mapping args);
varargs mixed query_listen_lock_text(mapping args);
varargs mixed query_listen_unlock_text(mapping args);

void set_knock_text(mixed text);
void set_listen_knock_text(mixed text);
varargs mixed query_knock_text(mapping args);
varargs mixed query_listen_knock_text(mapping args);

void set_not_open_text(mixed mess);
varargs mixed query_not_open_text(mapping args);

void set_door_long(mixed s);
void set_door_short(mixed s);
string door_short();
string door_long();

void create() {
  lockable::create();
  exit::create();
}

// splitted create() into create() and configure(), Coogan, 25-Mar-1998
void configure() {
  exit::configure();
  set_short(#'door_short);
  set_long(#'door_long);
  set_id(({ "door" }));
  set_name("door");

#if 0
// this is done by basic/handle already, Coogan, 25-Mar-1998
  listen_event("open", CANCEL_PRIO);
  listen_event("close",CANCEL_PRIO);
#endif
  listen_event("look", CANCEL_PRIO);
  listen_event("knock",CANCEL_PRIO);
  listen_event("knock");
  // lock and unlock are already awaited by lockable.c
}

// Ugh Aug-7-1995 -- usage of the new action-system
void init() {
  exit::init();
  add_action_rule("knock on <object>", "knock");
  add_action_rule("knock at <object>", "knock");
  add_action_rule("knock <object>", "knock");
  add_action_error_message("knock", "Knock on what?\n");
}

int apply_action(string str, int level, mixed args) {
  return
    lockable::apply_action(str,level,args) ||
    exit::apply_action(str,level,args);
}

void notify_destruct(object ob) {
  object door;
  if (remove_exit_on_destruct) {  // added { }, Coogan, 21-Nov-2001
    if (environment()) 
      environment()->remove_exit(query_direction());
  }
  else
    if (environment()) 
      environment()->add_exit(get_destination(),query_direction());
  if (remove_partner_on_destruct)
    door = get_other_door();
  remove_door();
  if (door) 
    destruct(door);
}

void notify_move (object from, object to) {
  if (from) 
    remove_door();
}

// added by Ugh Jun-06-1995
//static
status door_move_hook(string str, status silently) {
  mixed h;
  if (query_open())
    return 0;
#if 1  // Alfe 2006-Jun-27
  // we assume that ghosts can walk through doors (see also decision log):
  if (this_player()->query_ghost()) {
    if ((h=find_element(all_inventory(this_player()),
                        (: !$1->query_auto_load() :))) >= 0) {
      // has something material (non-auto_load) with him?
      notify_fail("As you try to walk as a ghost through the closed door,"
                  " your " +
                  describe(all_inventory(this_player())[h], ARTICLE_NONE) +
                  " prevents it.\n");
      return 1;
    }
    return 0;
  }
#endif
  if (!silently) {
    message(query_not_open_text());
  }
#if 1  // Coogan, 10-Oct-2001
  else
    notify_fail(query_not_open_text());
#endif
  return 1;
}

varargs void
set_door_exit(mixed dest, string dir, mixed hook, 
              mixed flags, mixed exit_str) {
  exit::set_door_exit(dest, dir, hook || #'door_move_hook, flags, exit_str);
  new = 1;
}

void set_open_direction(status d) {
  open_direction = d;
}

status query_open_direction() {
  return open_direction;
}

void set_remove_exit_on_destruct(status state) {
  remove_exit_on_destruct = state;
}

void set_remove_partner_on_destruct(status state) {
  remove_partner_on_destruct = state;
}

void set_update_on_reset(status state) {
  update_on_reset = state;
}

// moved the next from door_long() into an own function, Coogan, 27-May-2004
string query_door_state_description() {
  return query_open()
         ? query_open_state_description()
         // if not lockable, don't show the lockstate-desc. Coogan, 26-Feb-2001
         : (query_lockable() ? query_lock_state_description() + " and " : "") +
           query_open_state_description();
}

status door_id(string str) {
  int i;
  string *words, *states;
  if (!str)
    return 0;
  words = explode(str, " "); /* split the str into words */
  if ((words[0] == query_direction() || /* is the first word the direction? */
       (words[0][<3..] == "ern" && /* or does the first word end in -ern? */
        (i = member(wind_dirs, words[0][0..<4])) >= 0 &&
                                   /* and is the beginning of the first word
                                      one of the wind-directions? */
        wind_dirs[i] == query_direction())) &&
                                   /* and this direction is actually the 
                                      one of the door? */
      exit::id(implode(words[1..], " ")))
                                   /* and if the other words are a
                                      description of this door without 
                                      direction */
    return 1; /* then it is indeed an id of THIS door */
  if (words[<1] == query_direction() && sizeof(words) > 2
                        && member(pointing, words[<2]) >- 1
                        && exit::id(implode(words[0..<3], " ")))
    return 1;
  states = ({ query_open_state_description(), query_lock_state_description() });
  if (sizeof(words) > 1
                        && sizeof(({ words[0] }) & states)
                        && exit::id(implode(words[1..], " ")))
                                // added implode() sunblood 03-Oct-1999
    return 1;
  if (sizeof(words) > 3 && words[1] == "and"
                        && sizeof(({ words[0], words[2] }) & states)==2
                        && exit::id(implode(words[4..], " ")))
                                // added implode() sunblood 03-Oct-1999
    return 1;
  return exit::id(str) && !query_fakeitem_id(str);
}

status id(string str) {
  return door_id(str) || query_fakeitem_id(str);
}

void set_door_short(mixed s) {
  door_short = s;
}

string door_short() {
  return describe(funcall(door_short) || this_object(), ARTICLE_A) + 
          " (leading "+query_direction()+")";
}

void set_door_long(mixed s) {
  door_long = s;
}

string door_long() {
  string desc;

  if (!((desc = funcall(door_long)) || 
        ((desc = short()) && (desc = capitalize(desc)+".\n"))))
    desc = "";
  return                // Coogan, 27-May-2004
    desc + "It is " + query_door_state_description() + ".\n";
}

status do_action(string action, mapping args) {
  switch (action) {
  case "knock":
    if (args[G_OBJECT] != this_object() || query_fakeitem_id(args[G_OBJECT,1])) 
      break;
    send_event("knock",
               ([ E_AGENT  : this_player(); this_player()->query_name(),
                  E_TARGET : this_object(); 
                             describe(this_player(), ARTICLE_NONE) ]),
               environment());
    return 1;
  }
  return exit::do_action(action,args);
}

void set_new(status n) {
  new = n;
}

void refresh() {
  object other_door;
  if (update_on_reset) {
    if (other_door = get_other_door()) 
      other_door->set_new(1);
    init_door();
  }
}

void init_door() {
  status o, l;
  object other_door;
  o = funcall(default_open);
  l = funcall(default_locked);
  if (other_door = get_other_door())
    call_other_2ref(other_door,"restore_door", &o, &l);
  set_open_state(o);
  set_lock_state(l);
  new = 0; /* not new anymore */
}

void restore_door(status open, status locked) {
  if (!new) { /* we only can restore something we have */
    open = lockable::query_open();
    locked = lockable::query_lock();
  }
}

void set_default_open(mixed o) {
  default_open = o;
}

mixed query_default_open() {  // Coogan, 21-Nov-2001
  return funcall(default_open);
}

void set_default_locked(mixed l) {
  default_locked = l;
}

mixed query_default_locked() {  // Coogan, 21-Nov-2001
  return funcall(default_locked);
}

status query_lock() {
  if (new)
    init_door();
  return lockable::query_lock();
}

status query_open() {
  if (new)
    init_door();
  return lockable::query_open();
}

private void tell_room_message(mixed mess) {
  if (stringp(mess))
    send_message(({ M_ROOM, environment(), mess }));
  else
    message(mess);
}

void receive_event(mapping event, string type, int prio) {
  mapping e;
  object who, other_door;
  if (type == "knock" && !prio) {
    if (event[E_TARGET] == this_object())
      message(query_knock_text(event),event[E_AGENT]);
    else if (event[E_PARTNER] == this_object())
      tell_room_message(query_listen_knock_text(event));
  } else if (prio == CANCEL_PRIO) {
    switch (type) {
      case "open":
      case "close":
      case "lock":
      case "unlock":
      case "knock":
        if (event[E_TARGET] != this_object()) 
          return;
        if (event[E_PARTNER])
          break;
        event[E_PARTNER] = get_other_door() || NO_PARTNER;
        if (objectp(event[E_PARTNER]))  // Coogan, 13-Nov-1998
          event[E_PARTNER,1] = describe(event[E_PARTNER], ARTICLE_NONE);
        send_event(type, event,
                   objectp(event[E_PARTNER])
                   ? ({ environment(event[E_AGENT]), 
                        environment(event[E_PARTNER]) })
                   : ({ environment(event[E_AGENT]) }));
        cancel_event();
        return;
      case "look" :
        if (event[E_TYPE] != "look_into" ||
            event[E_TO] != environment() ||
            !get_other_door() ||    // Carador, 14-Aug-1997
            environment(get_other_door()) != event[E_FROM] ||
            query_open())
          return;
        event[E_SUCCESS] = 0;
        break;
      default:
        break;
    }
  }
  lockable::receive_event(event, type, prio);
}

status do_open(mapping action) {
  if (!action)
    action = ([ E_AGENT  : this_player();
                           this_player() && this_player()->query_name(),
                E_TARGET : this_object();
                           describe(this_object(), ARTICLE_NONE) ]);
  if (!action[E_PARTNER])
    action[E_PARTNER] = get_other_door();
  if (action[E_PARTNER])  // Coogan, 13-Nov-98
    action[E_PARTNER,1] = describe(action[E_PARTNER], ARTICLE_NONE);
  if (action[E_PARTNER] != this_object()) {
    return
      lockable::do_open(action) && 
      (!objectp(action[E_PARTNER]) || action[E_PARTNER]->do_open(action));
  } else if (action[E_TARGET]->query_open()) {
    open(); // took this line out of the 'if' -- Ugh Apr-07-1999
    tell_room_message(query_listen_open_text(action));
    return 1;
  }
}

status do_close(mapping action) {
  if (!action)
    action = ([ E_AGENT  : this_player();
                           this_player() && this_player()->query_name(),
                E_TARGET : this_object();
                           describe(this_object(), ARTICLE_NONE) ]);
  if (!action[E_PARTNER])
    action[E_PARTNER] = get_other_door();
  if (action[E_PARTNER])  // Coogan, 13-Nov-98
    action[E_PARTNER,1] = describe(action[E_PARTNER], ARTICLE_NONE);
  if (action[E_PARTNER] != this_object()) {
    return
      lockable::do_close(action) && 
      (!objectp(action[E_PARTNER]) || action[E_PARTNER]->do_close(action));
  } else if (!action[E_TARGET]->query_open()) {
    close(); // took this line out of the 'if' -- Ugh Apr-07-1999
    tell_room_message(query_listen_close_text(action));
    return 1;
  }
}

status do_lock(mapping action) {
  if (!action)
    action = ([ E_AGENT  : this_player();
                           this_player() && this_player()->query_name(),
                E_TARGET : this_object();
                           describe(this_object(), ARTICLE_NONE) ]);
  if (!action[E_PARTNER])
    action[E_PARTNER] = get_other_door();
  if (action[E_PARTNER] != this_object()) {
    return
      lockable::do_lock(action) && 
      (!objectp(action[E_PARTNER]) || action[E_PARTNER]->do_lock(action));
  } else if (action[E_TARGET]->query_lock()) {
    lock(); // took this line out of the 'if' -- Ugh Apr-07-1999
    tell_room_message(query_listen_lock_text(action));
    return 1;
  }
}

status do_unlock(mapping action) {
  if (!action)
    action = ([ E_AGENT  : this_player();
                           this_player() && this_player()->query_name(),
                E_TARGET : this_object();
                           describe(this_object(), ARTICLE_NONE) ]);
  if (!action[E_PARTNER])
    action[E_PARTNER] = get_other_door();
  if (action[E_PARTNER] != this_object()) {
    return
      lockable::do_unlock(action) && 
      (!objectp(action[E_PARTNER]) || action[E_PARTNER]->do_unlock(action));
  } else if (!action[E_TARGET]->query_lock()) {
    unlock(); // took this line out of the 'if' -- Ugh Apr-07-1999
    tell_room_message(query_listen_unlock_text(action));
    return 1;
  }
}

void set_listen_open_text(mixed text) {
  listen_open_text = text;
}

void set_listen_close_text(mixed text) {
  listen_close_text = text;
}

void set_listen_lock_text(mixed text) {
  listen_lock_text = text;
}

void set_listen_unlock_text(mixed text) {
  listen_unlock_text = text;
}

varargs mixed query_listen_open_text(mapping args) {
  if (closurep(listen_open_text))
    return funcall(listen_open_text,this_object(),args);
  return listen_open_text ||
#if 0  // Coogan, 01-Jul-2003
                                                   // , 0, -1 by Cara, May-1996
         capitalize(describe(this_object(),ARTICLE_THE, 0, -1)) +
         " is opened from the other side."; // removed \n Carador, 14-Sep-1997
#else
         ({ ({ M_ROOM, environment(this_object()),
               M_SUPPRESS_VIEW, environment(get_other_door()),
               M_ME_THE, M_ME_VERB, "be", " opened from the other side." }) });
#endif
}

varargs mixed query_listen_close_text(mapping args) {
  if (closurep(listen_close_text))
    return funcall(listen_close_text,this_object(),args);
  return listen_close_text ||
#if 0  // Coogan, 01-Jul-2003
                                        //, 0, -1 by Carador, further
                                        // changes will be undocumented :)
         "You see "+describe(this_object(), ARTICLE_THE, 0, -1) + " close.";
#else
         ({ ({ M_ROOM, environment(this_object()),
               M_SUPPRESS_VIEW, environment(get_other_door()),
               "you see ", M_ME_THE, " close." }) });
#endif
}

varargs mixed query_listen_lock_text(mapping args) {
  if (closurep(listen_lock_text))
    return funcall(listen_lock_text,this_object(),args);
  return listen_lock_text ||
#if 0  // Coogan, 01-Jul-2003
         "Someone on the other side of " +
         describe(this_object(), ARTICLE_THE, 0, -1) + " locked it.";
#else
         ({ ({ M_ROOM, environment(this_object()),
               M_SUPPRESS_VIEW, environment(get_other_door()),
               "Someone on the other side of ", M_ME_THE, " locked it." }) });
#endif
}

varargs mixed query_listen_unlock_text(mapping args) {
  if (closurep(listen_unlock_text))
    return funcall(listen_unlock_text,this_object(),args);
  return listen_unlock_text ||
#if 0  // Coogan, 01-Jul-2003
         "You hear a faint 'click' as " +
         describe(this_object(), ARTICLE_THE, 0, -1) + " is unlocked.";
#else
         ({ ({ M_ROOM, environment(this_object()),
               M_SUPPRESS_VIEW, environment(get_other_door()),
               "you hear a faint 'click' as ", M_ME_THE, " is unlocked." }) });
#endif
}

varargs mixed query_listen_knock_text(mapping args) {
  if (closurep(listen_knock_text))
    return funcall(listen_knock_text,this_object(),args);
  return listen_knock_text ||
#if 0  // Coogan, 01-Jul-2003
         "You hear someone knocking at the other side of " +
         describe(this_object(), ARTICLE_THE, 0, -1) + ".";
#else
         ({ ({ M_ROOM, environment(this_object()),
               M_SUPPRESS_VIEW, environment(get_other_door()),
               "you hear someone knocking at the other side of ",
               M_ME_THE, "." }) });
#endif
}

varargs mixed query_knock_text(mapping args) {
  if (closurep(knock_text))
    return funcall(knock_text,this_object(),args);
  return knock_text ||
         ({ ({ M_PL_THE, M_PL_VERB, "knock", " on ", M_ME_THE,
               " 'knock knock knock'." }) });
}

void set_listen_knock_text(mixed text) {
  listen_knock_text = text;
}

void set_knock_text(mixed text) {
  knock_text = text;
}

void set_not_open_text(mixed text) {
  not_open_text = text;
}

varargs mixed query_not_open_text(mapping args) {
  if (closurep(not_open_text)) 
    return funcall(not_open_text,this_object(),args);
  return not_open_text ||
         "But " + describe(this_object(), ARTICLE_THE, 0, -1) +
         " is not open!\n";
}

void remote_set_open_state(status open_state) {
  object partner;
  partner = get_other_door();
  if (open_state)
    open();
  else
    close();
  if (partner)
    if (open_state)
      partner->open();
    else
      partner->close();
}

