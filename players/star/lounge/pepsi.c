/*
 *      File:                 /players/star/objs/pepsi.c
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
  set_name("pepsi");
  set_alias("pepsi");
  set_short("A Can of Pepsi");
  set_long("A red and blue can filled with Pepsi.\n");
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
  if(str != "pepsi")
  {
    notify_fail("You can only \"drink\" the \"pepsi\".\n");
    return 0;
  }

  write("You drink the Pepsi and recycle the can.\n");
  say((string)this_player()->query_name()+" drinks a Pepsi and recycles the can.\n");
  destruct(this_object());

  return 1;
}
