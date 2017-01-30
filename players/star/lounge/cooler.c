/*
 *      File:                 /players/star/lounge/cooler.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2005 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               12/31/2005
 *      Notes:
 *      Change History:
 */

inherit "obj/treasure.c";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("water cooler");
  set_alias("cooler");
  set_short("A Water Cooler");
  set_long("This is an upside down bottle of water on a stand.  There is a lever\n"+
    "in the front of the stand that can be pulled and a stack of paper cups\n"+
    "in a holder on the side.\n");
  set_value(0);
}

void init()
{
  ::init();
  add_action("pull", "pull");
}

int pull(string str)
  {
  if(!str)
  {
    notify_fail("Pull what?\n");
    return 0;
  }
  if(str != "lever")
  {
    notify_fail("You can only \"pull\" the \"lever\".\n");
    return 0;
  }

  write("You grab a paper cup from the holder and fill it with water.\n");
  say((string)this_player()->query_name()+" pours a cup of water from the cooler.\n");
  move_object(clone_object("/players/star/lounge/water.c"),this_player());

  return 1;
}
