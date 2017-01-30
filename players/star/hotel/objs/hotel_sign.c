/*
 *      File:                 /players/star/objs/hotel_sign.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2006 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               02/08/2006
 *      Notes:
 *      Change History:
 */

inherit "obj/treasure.c";

#include <ansi.h>

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("hotel sign");
  set_short(HIR+"A WOODEN SIGN"+NORM);
  set_alias("sign");
  set_long("A carved wooden sign that you can \"read\".\n");
  set_weight(50);
  set_value(0);
}

void init()
{
  ::init();
  add_action("read", "read");
}

int read(string str)
  {
  if(!str)
  {
    notify_fail("Open what?\n");
    return 0;
  }
  if(str != "sign" && str != "wooden sign")
  {
    notify_fail("You can only \"read\" the \"sign\".\n");
    return 0;
  }

  write("___________________________________________________\n"+
    "|   ___     ___     _       ___ ___     _   _      |\n"+
    "|    |  |_| |_     / \\ \\  / |_  |_/ |  / \\ / \\ |/  |\n"+
    "|    |  | | |__    \\_/  \\/  |__ | \\ |_ \\_/ \\_/ |\\  |\n"+
    "|                     _  ___ ___                   |\n"+
    "|                |_| / \\  |  |_  |                 |\n"+
    "|                | | \\_/  |  |__ |_                |\n"+
    "|___________________________________________________\n"+
    "                          ||\n"+
    "                          ||\n"+
    "                          ||\n"+
    "                          ||\n"+
    "                          ||\n");
    say((string)this_player()->query_name()+" reads the sign.\n");

  return 1;
}
