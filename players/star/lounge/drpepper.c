/*
 *      File:                 /players/star/objs/drpepper.c
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
  set_name("drpepper");
  set_alias("pepper");
  set_short("A Can of Dr. Pepper");
  set_long("A burgundy can filled with Dr. Pepper.\n");
  set_value(0);
}

void init()
{
  ::init();
  add_action("drink", "drink");
}

int drink(string str)
{
  if(!str)
  {
    notify_fail("Drink what?\n");
    return 0;
   }
  if(str != "pepper" && str != "dr pepper")
  {
   notify_fail("You can only \"drink\" the \"dr pepper\".\n");
    return 0;
  }

  write("You drink the Dr. Pepper and recycle the can.\n");
  say((string)this_player()->query_name()+" drinks a Dr. Pepper and recycles the can.\n");
  destruct(this_object());

  return 1;
}
