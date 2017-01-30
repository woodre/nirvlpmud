/*
 *      File:                 /players/star/objs/water.c
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
  set_name("water");
  set_alias("water");
  set_short("A Cup of Water");
  set_long("A paper cup filled with water.\n");
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
  if(str != "water")
  {
    notify_fail("You can only \"drink\" the \"water\".\n");
    return 0;
  }

  write("You drink the water and throw the cup in the trash.\n");
  say((string)this_player()->query_name()+" drinks some water and throws the cup in the trash.\n");
  destruct(this_object());

  return 1;
}
