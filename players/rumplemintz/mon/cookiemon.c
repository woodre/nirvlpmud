#pragma strong_types

#include <ansi.h>

#define START_ROOM "/room/plane11"

inherit "obj/monster";

void reset(status arg) {
  ::reset(arg);
  set_name("cookie monster");
  set_alias("monster");
  set_alt_name("cookie");
  set_short(BLU+"Cookie Monster"+NORM);
  set_long(""+
BLU+"Cookie Monster"+NORM+" is a voracious monster. Covered with "+BLU+"blue"+
NORM+" fur and possesing\n"+
"a pair of googly eyes, Cookie Monster has an insatiable appetite. As his \n"+
"name implies, his primary craving is cookies, but he can (and often does)\n"+
"consume anything and everything, from apples and pie to letters, flatware,\n"+
"hubcaps, and players. Usually when he eats something, he makes loud \n"+
"munching noises\n");
  set_level(10);

  /* Chat setup */
  set_chat_chance(5);
  load_chat("Cookie Monster says: Me want cookie!\n");

  /* Wander setup */
  set_wander(1);
  set_wander_interval(10);
  set_wander_realm("/room/");
  
  /* catch_tell setup */
  set_object(this_object());
  set_function("cookie_receive");
  set_type("gives");
  set_match("");
  set_function("handle_arrival");
  set_type("arrives");
  set_match("");
  
  /* Move me to the starting room */
  move_object(this_object(), START_ROOM);
}

void cookie_receive(string str) {
  object target, ob;
  string who, what, me;
  
  if (sscanf(str, "%s give %s to %s.", who, what, me) !=3 )
    return;
  ob = present(what, this_object());
  if (!ob || !ob->id("cookie"))
#if 1
  {
    say("ID of object doesn't == cookie \n");
    return;
  }
#else
    return;
#endif
  target = present(lower_case(who), environment(this_object()));
  if (!target)
#if 1
  {
    say("There is no target\n");
    return;
  }
#else
    return;
#endif
  if (me != "Cookie" && me != "Monster")
#if 1
  {
    say("me doesn't equal Cookie or Monster\n");
    return;
  }
#else
    return;
#endif
  say("Cookie Monster hungrily eats the cookie!\n");
  say("Cookie Monster says: OMM-nom-nom-nom...\n");
  destruct(ob);
}

void handle_arrival(string str) {
  object target;
  string who, rest;
  
  if (sscanf(str, "%s arrives%s", who, rest) != 2)
    return;
  target = present(lower_case(who), environment(this_object()));
  if (!target)
    return;
  if (target->query_level() >= 20) {
    say("Cookie Monster tries to eat " + who + " but fails miserably!\n");
  }
  say("Cookie Monster eats " + who + "!\n");
  say("Cookie Monster says: OMM-nom-nom-nom...\n");
  move_object(target, this_object());
}

/* Overload the next function from obj/monster so that it keeps wandering */
status test_if_any_here() { return 1; }
