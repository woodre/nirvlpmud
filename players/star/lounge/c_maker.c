/*
 *      File:                 /players/star/lounge/c_maker.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2005 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               12/30/2005
 *      Notes:
 *      Change History:
 */

inherit "obj/treasure.c";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("coffee maker");
  set_alias("maker");
  set_short("A Coffee Maker");
  set_long("This is a small coffee maker with a fresh pot on the warmer.  There is\n"+
    "a stack of styrofoam cups in a holder on the side so that you can pour\n"+
    "yourself some coffee if you'd like.\n");
  set_value(0);
}

void init()
{
  ::init();
  add_action("pour", "pour");
}

int pour(string str)
  {
  if(!str)
  {
    notify_fail("Pour what?\n");
    return 0;
  }
  if(str != "coffee")
  {
    notify_fail("You can only \"pour\" the \"coffee\".\n");
    return 0;
  }

  write("You pour yourself a styrofoam cup full of coffee.\n");
  say((string)this_player()->query_name()+" pours a cup of coffee.\n");
  move_object(clone_object("/players/star/lounge/coffee.c"),this_player());

  return 1;
}
