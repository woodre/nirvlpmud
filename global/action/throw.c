/*************************************************************************
  throw.c -- throw-action written by Ugh Feb-1996 for Tubmud
*************************************************************************/

#pragma strong_types  // Coogan, 04-Jan-02

#include <event.h>
#include <message.h>
#include <grammar.h>
#include <describe.h>
#include <skilltree.h>
#include <server.h>
#include <skills.h>

inherit "basic/parser";
inherit "basic/action";

private void receive_throw_event(mapping e,string t,int p);

void create() {
  action::create();
  set_skill_path(S_THROW);
  set_command("throw");
  set_specific(0);
  set_function("parse_action");
  set_reward(0);

  add_rule("throw "G_OBJECT" at "G_INDIRECT,        "throw_at");
  add_rule("throw "G_OBJECT" under "G_INDIRECT,     "throw_under");
  add_rule("throw "G_OBJECT" to "G_INDIRECT,        "throw_to");
  add_rule("throw "G_OBJECT" towards "G_LIVING,     "throw_to");
  add_rule("throw "G_OBJECT" toward "G_LIVING,      "throw_to");
  add_rule("throw "G_OBJECT" along "G_INDIRECT,     "throw_along");
  add_rule("throw "G_OBJECT" into "G_INDIRECT,      "throw_into");
  add_rule("throw "G_OBJECT" onto "G_INDIRECT,      "throw_onto");
  add_rule("throw "G_OBJECT" on "G_INDIRECT,        "throw_onto");
  add_rule("throw "G_OBJECT" up onto "G_INDIRECT,   "throw_onto");
  add_rule("throw "G_OBJECT" over "G_INDIRECT,      "throw_over");
  add_rule("throw "G_OBJECT" around "G_INDIRECT,    "throw_around");
  add_rule("throw "G_OBJECT" down from "G_INDIRECT, "throw_from");
  add_rule("throw "G_OBJECT" down on "G_INDIRECT,   "throw_down");
  add_rule("throw "G_OBJECT" across "G_INDIRECT,    "throw_across");
  add_rule("throw "G_OBJECT" "G_EXIT,               "throw_where");
  add_rule("throw "G_OBJECT,                        "throw");

  add_error_message("throw",
                    ({ "Throw something at/into/over/around/to something or "
                       "someone.\n", -1 }));
  set_global_listening_event("throw", 1);
  listen_event("throw", EPRIO_HANDLE, #'receive_throw_event);
}

int do_action(string action, mapping args) {
  object ob;
  mapping event;
  if (strstr(action, "throw", 0)) // 'throw' not at the beginning of the string
    return 0;
  event = ([ E_TARGET     : args[G_OBJECT];   args[G_OBJECT,1],
             E_OBJECT     : args[G_INDIRECT]; args[G_INDIRECT,1],
             E_ID         : args[G_OBJECT,1]; 0,
             E_AGENT      : this_player();    this_player()->query_name(),
             E_WHERE      : args[G_INDIRECT,1] || args[G_EXIT]; 0,
             E_PREPOSITION: (action != "throw" && action[6..]); 0
          ]);
  if (action != "throw") {
    if (!present(args[G_OBJECT], this_player()))
      notify_fail("You don't have "+
                  (describe(args[G_OBJECT] == environment(this_player()) ? 
                            args[G_OBJECT,1] : 
                            args[G_OBJECT], ARTICLE_THE)|| "that")+".\n");
    else
      notify_fail("You can't throw "+
                  (describe(args[G_OBJECT],ARTICLE_THE)||"this")+" "+
                  (args[G_EXIT] ? 
                   "there." : 
                   action[6..]+" "+
                   (describe(args[G_INDIRECT] == environment(this_player()) ?   
                             args[G_INDIRECT,1] : 
                             args[G_INDIRECT],ARTICLE_THE)|| "that")+ 
                             ".")+ "\n");
  } else
    notify_fail("You can't throw "+
                (describe(args[G_OBJECT] == environment(this_player()) ? 
                          args[G_OBJECT,1] : 
                          args[G_OBJECT], ARTICLE_THE)|| "that")+".\n");
  send_event("throw", event, environment(this_player()));
  if (event[E_CANCELLED])
    return 1;

  if (event[E_SUCCESS] == -1)
    return 1;

  if (event[E_SUCCESS] > 0) {
    if (event[E_SUCCESS] > 1)
      this_player()->add_skill_points(query_skill_path(),
                                      SE_SKILLS->query_reward(this_player(),
                                                              event[E_SUCCESS],
                                    (event[E_SUCCESS]/IMPROVE_ROUTINE * 5 + 50),
                                                              S_THROW));
    else if (!random(5))
      this_player()->add_skill_points(query_skill_path(),
                                      SE_SKILLS->query_reward(this_player(),
                                                              event[E_SUCCESS],
                                                              50, S_THROW));
  }
  return event[E_SUCCESS];
}

// this is the default case for all objects without an own apply_action()
// (see below for details on own implementations)  Alfe 2002-Sep-18
private int apply_action(string action, int level, mapping args) {
  mixed m;
  switch (action) {
  default:
    return 0;
  case "throw":
    if (args[E_AGENT] != environment(args[E_TARGET]))
      return notify_fail("First take " +
                         describe(args[E_TARGET,1], ARTICLE_THE) + "!\n");
    if (args[E_TARGET]->drop(1))
      return notify_fail("You can't throw that.\n"), 0;
    if (args[E_OBJECT]) {  // target to throw at/to given
      if (environment(args[E_OBJECT]) != environment(args[E_AGENT]) &&
          args[E_OBJECT] != environment(args[E_AGENT]))
        return notify_fail("You could throw something at a living but not at"
                           " specific items carried by a living.\n"), 0;
      m = ({ M_THE,M_ARG,E_AGENT,M_VERB,"throw",M_ARG,E_AGENT,
             M_OBJECT,M_THE,M_ARG,E_TARGET," ",M_ARG,E_PREPOSITION, " " });
      if (args[E_OBJECT]->query_fakeitem_id(args[E_OBJECT,1]))
        m += ({ M_THE, args[E_OBJECT,1], " of ", M_OBJECT, M_NONE,
                M_ARG,E_OBJECT,"." });
      else
        m += ({ M_OBJECT,M_THE,M_ARG,E_OBJECT,"." });
      switch (args[E_PREPOSITION]) {
      default:
        return 0;  // don't know what to do then, so don't do anything.
      case "at":
        send_message(m,args);
        if (random(2))  // should be dependent on skill  Alfe 2002-Sep-18
          send_message(({ M_THE,M_ARG,E_TARGET,M_VERB,"miss",M_ARG,E_TARGET,
                          M_OBJECTIVE,M_ARG,E_OBJECT,"." }),args);
        else
          send_message(({ M_THE,M_ARG,E_TARGET,M_VERB,"hit",M_ARG,E_TARGET,
                          M_OBJECTIVE,M_ARG,E_OBJECT,"." }),args);
        move_object(args[E_TARGET], // can be fakeitem, Chameloid, 9-Dec-1998
                    environment(args[E_OBJECT]) || args[E_OBJECT]);
        break;
      case "to":
        send_message(m,args);
        if (random(4))  // should be dependent on skill  Alfe 2002-Sep-18
          send_message(({ M_THE,M_ARG,E_TARGET,M_VERB,"land",M_ARG,E_TARGET,
                          " in front of ",M_OBJECTIVE,M_ARG,E_OBJECT,"." }),
                       args);
        else
          send_message(({ M_THE,M_ARG,E_TARGET,M_VERB,"hit",M_ARG,E_TARGET,
                          M_OBJECTIVE,M_ARG,E_OBJECT,"." }),args);
        move_object(args[E_TARGET], // can be fakeitem, Chameloid, 9-Dec-1998
                    environment(args[E_OBJECT]) || args[E_OBJECT]);
        break;
      }
    }
    else {  // no target to throw at given
      send_message(({ M_THE,M_ARG,E_AGENT,M_VERB,"throw",M_ARG,E_AGENT,
                      M_OBJECT,M_THE,M_ARG,E_TARGET," upwards and ",
                      M_PRONOUN,M_ARG,E_TARGET,M_VERB,"fall",M_ARG,E_TARGET,
                      " down again." }),args);
      move_object(args[E_TARGET],environment(args[E_AGENT]));
    }
    return 1;
  }
  return 0;  // Coogan, 26-Mar-2011
}

private int apply_throw_action(mapping e) {
  int sk;
  sk = this_player()->query_modified_skill(query_skill_path());
  return ((e[E_OBJECT] ||
           environment(this_player()))->apply_action(query_skill(), sk, e) ||
          e[E_TARGET]->apply_action(query_skill(), sk, e)                  ||
          apply_action(query_skill(), sk, e));
}

private void receive_throw_event(mapping e, string t, int p) {
  if (t != "throw" || p != EPRIO_HANDLE || e[E_HANDLED])
    return;
  e[E_HANDLED] = 1;
  e[E_SUCCESS] = 
    with_player(e[E_AGENT], #'apply_throw_action, e);
}

/* To use this action, define in your throwable object or the object
   that can be 'involved' (e.g. thrown at) in the throwing a function 
   apply_action() like this (only a rudimentary example):

status apply_action(string action, int skill, mixed args) {
  switch (action) {
  case "throw":
    switch (args[E_PREPOSITION]) {
    case "at":
      if (args[E_OBJECT] == this_object()) // shall be thrown against us
      ... move of thrown object ...
      ... messages describing what happens ...
      break;
    case "over":
      ... etc. ...
    default: 
      return 0;
    }
    break;
  default:
    return 0;
  }
  return 1;
}

args is a mapping that was formerly sent as throw-event.
It contains the fields

E_AGENT: who tries to throw something
E_TARGET: what is to be thrown?
E_ID: the matched id of the to-be-thrown object
E_PREPOSITION: the preposition used with throw 
               (at/over/around/down/to/from/into/onto/along/across) 
               if another object was involved, or 'where' if an exit was given.
E_OBJECT: the other object involved in the throw (if there was one).
E_WHERE: either the id of the other involved object or the direction of the
         exit.

*/

string query_info(string str) {
  return ("Many things can be thrown. You could try to throw something that"
          " you carry\n"
          "'at' someone else or something, (e.g. a monster or a wall)\n"
          "'into' something, (e.g. a bin or the sea)\n"
          "'onto' something, (e.g. a table)\n"
          "'over' something, (e.g. a roof-beam),\n"
          "'to' or 'toward(s)' someone,\n"
          "'down from' something, (e.g. a cliff or a tree),\n"
          "'up onto' something (e.g. a roof)\n"
          "'along' something, (e.g. a riverbank),\n"
          "'across' something, (e.g. a street or a brook),\n"
          "into a direction where an exit leads.\n");
}

