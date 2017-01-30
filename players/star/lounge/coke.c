/*
 *      File:                 /players/star/objs/coke.c
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
  set_name("coke");
  set_alias("coke");
  set_short("A Can of Coke");
  set_long("A red and white can filled with Coke.\n");
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
  if(str != "coke")
  {
    notify_fail("You can only \"drink\" the \"coke\".\n");
    return 0;
  }

  write("You drink the Coke and recycle the can.\n");
  say((string)this_player()->query_name()+" drinks a Coke and recycles the can.\n");
  destruct(this_object());

  return 1;
}
