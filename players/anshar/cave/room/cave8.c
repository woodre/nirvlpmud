#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
#include "/players/anshar/closed/mydef.h"

inherit "room/room";

reset(arg)
{
  if (arg) return 0;
  set_light(0);
  short_desc="A dark cave";
  long_desc="     An apparently empty room. \n";
  items =
  ({
    "stone",      "A large stone you might be able to lift",
  });
  if (!present("money"))
  {
	  object money;
    money = clone_object("obj/money");
	  move_object(money, "/players/anshar/cave/room/cave8");
	  call_other(money, "set_money",(random(10000)+20000));
  }
}

init()
{
  ::init();
  add_action ("search", "search");
  add_action ("lift_stone", "lift");
}

search()
{
  write("Aha! You find a large stone you might lift\n");
  return 1;
}

lift_stone(str)
{
  if(!str) return 0;
  if(str != "stone") { write("Lift what?\n"); return 1;}
  if(call_other(this_player(), "query_attrib", "str") < 19) {
  write("You are not strong enough!\n"); return 1;}
  write("You lift the stone and quickly slide out of the hole.\n");
  this_player()->move_player("cave#"+CROOM+"cave7");
  return 1;
}
