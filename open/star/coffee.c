/*
 *      File:                 /players/star/objs/coffee.c
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
  set_name("coffee");
  set_alias("coffee");
  set_short("A Cup of Coffee");
  set_long("A styrofoam cup filled with coffee.\n");
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
  if(str != "coffee")
  {
    notify_fail("You can only \"drink\" the \"coffee\".\n");
    return 0;
  }

  write("You drink the coffee and throw the cup in the trash.\n");
  say((string)this_player()->query_name()+" drinks some coffee and throws the cup in the trash.\n");
  destruct(this_object());

  return 1;
}
