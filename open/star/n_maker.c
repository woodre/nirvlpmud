/*
 *      File:                 /players/star/toys/n_maker.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2005 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               12/31/2005
 *      Notes:
 *      Change History:
 */

#include <ansi.h>

inherit "obj/treasure.c";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("noise maker");
  set_alias("maker");
  set_short(HIY+"A NEW YEAR'S NOISE MAKER!!"+NORM);
  set_long("A short plastic tube with "+HIR+"colored streamers"+NORM+" on the end.  It looks like\n"+
    "it might make a fun noise if you blow on it.\n");
  set_weight(1);
  set_value(0);
}

void init()
{
  ::init();
  add_action("blow", "blow");
}

int blow(string str)
{
  if(!str)
  {
    notify_fail("Blow what?\n");
    return 0;
  }
  if(str != "maker" && str != "tube")
  {
    notify_fail("You can only \"blow\" the \"tube\".\n");
    return 0;
  }

  write("You blow on the "+HIB+"NOISE MAKER "+NORM+"and it makes a loud "+HIG+"SQUEAL"+NORM+"!!\n");
  say((string)this_player()->query_name()+" blows on a "+HIB+"NOISE MAKER "+NORM+" and it makes a loud "+HIG+"SQUEAL"+NORM+"!!\n");

  return 1;
}
