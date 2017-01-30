/*
File: snow.c
Author: Feldegast
Date: 9/7/01
Description:
  A pile of snow created by crystallizing the air.
*/
#include "../defs.h"

inherit "/obj/treasure.c";

int count;

void reset(int arg)
{
  if(arg)
  {
    tell_room(environment(), "The snow melts as it becomes warm again and the sun starts to shine.\n");
    destruct(this_object());
    return;
  }
  set_id("snow");
  set_short("A pile of "+HIW+"snow"+NORM);
  set_long(
    "This is a thick pile of fresh snow that you can use to 'throw' snowballs\n"+
    "at people.\n"
  );
  set_weight(500);
  set_value(0);
  count = 0;
  call_out("snow", 5);
  call_out("reset", 300, 1);
}

get() { return 0; }

void init()
{
  add_action("cmd_throw", "throw");
}

int cmd_throw(string str)
{
  string what, who;
  object targ;
  string msg;

  if(!str || sscanf(str, "%s at %s", what, who) != 2)
  {
    notify_fail("Throw what at who?\n");
    return 0;
  }

  if(what != "snow" && what != "snowball")
  {
    notify_fail("That is not here.\n");
    return 0;
  }

  if(!(targ=present(who, environment(TP))))
  {
    write("That person is not here.\n");
    return 1;
  }

  if(!((string)targ->query_name()))
  {
    write("You can't throw a snowball at that.\n");
    return 1;
  }

  count++;

  write("You throw a "+HIW+"snowball"+NORM+" at "+capitalize(who)+"!\n");
  tell_object(targ, TPN+" throws a "+HIW+"snowball"+NORM+" at you!\n");
  tell_room(environment(), TPN+" throws a "+HIW+"snowball"+NORM+" at "+(string)targ->query_name()+"!\n", ({ TP, targ }));

  switch(random(3))
  {
    case 0: msg = (string)targ->query_name()+" gets hit upside the head!\n";
            break;
    case 1: msg = (string)targ->query_name()+" gets hit in the butt!\n";
            break;
    case 2: msg = (string)targ->query_name()+" shivers as a piece of ice slides down "+(string)targ->query_possessive()+" collar.\n";
            break;
  }

  tell_room(environment(), msg);

  if(count > 20)
    call_out("reset", 1, 1);

  return 1;
}

void snow()
{
  string msg;

  if(!environment()) return;

  switch(random(4))
  {
    case 0: msg = "It is "+HIW+"snowing"+NORM+".\n";
            break;
    case 1: msg = "You stick your tongue out and catch a " + HIC + "snowflake" + NORM + ".\n";
            break;
    case 2: msg = "A single perfect " + HIC + "snowflake" + NORM + " falls to the ground.\n";
            break;
    case 3: msg = "A flurry of fresh white " + HIW + "snow" + NORM + " blows around you.\n";
            break;
  }
  count--;
  tell_room(environment(), msg);
  call_out("snow", 10+random(30));
}