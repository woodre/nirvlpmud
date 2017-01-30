/*
 *      File:                 /players/star/toys/towel.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2006 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               02/05/2006
 *      Notes:
 *      Change History:
 */

#include <ansi.h>

inherit "obj/treasure.c";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("terrible towel");
  set_alias("towel");
  set_short(HIY+"A Terrible Towel"+NORM);
  set_long("A "+HIY+"yellow towel"+NORM+" with black writing that says \"Myron Cope's Official\n"+
    "Terrible Towel, a Pittsburgh Original.\"  Steeler fans wave these at\n"+
    "games.  Maybe you could try it.\n");
  set_weight(1);
  set_value(0);
}

void init()
{
  ::init();
  add_action("wave", "wave");
}

int wave(string str)
{
  if(!str)
  {
    notify_fail("Wave what?\n");
    return 0;
  }
  if(str != "towel" && str != "terrible towel")
  {
    notify_fail("You can only \"wave\" the \"towel\".\n");
    return 0;
  }

  write("You wave the "+HIY+"Terrible Towel "+NORM+"and scream \"GO STEELERS!\"\n");
  say((string)this_player()->query_name()+" waves the "+HIY+"Terrible Towel "+NORM+"and screams \"GO STEELERS!\"\n");

  return 1;
}
