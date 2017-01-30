#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
#include "/players/anshar/closed/mydef.h"

inherit "room/room";

reset(arg)
{
  if (arg) return 0;
  set_light(0);
  short_desc="A dark cave";
  long_desc="     An apparently empty room. \n";
  dest_dir =
  ({
    CROOM+"cave6", "north",
  });
  items =
  ({
    "stone",      "A large stone you might be able to lift",
  });
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
  write("You lift the stone and quickly slide into the hole beneath.\n");
  this_player()->move_player("cave#"+CROOM+"cave8");
  return 1;
}
