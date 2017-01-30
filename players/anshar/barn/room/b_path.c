#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
#include "/players/anshar/closed/mydef.h"

inherit "room/room";

reset(arg)
{
  if (arg) return 0;
  set_light(1);
  short_desc=("A barn");
  long_desc="A barn.\n";
  items =
  ({
    "barn",  "A barn",
  });
  dest_dir =
  ({
    FROOM+"path4", "east",
  });
}

init()
{
  ::init();
  add_action ("enter_barn", "enter");
}

enter_barn(str)
{
  if(!str) return 0;
  if(str != "barn") { write("enter what?\n"); return 1;}
  if (this_player()->query_level() > 5)
  {
    write("You have no desire to enter there.\n");
    return 1;
  }
  write("You enter the barn.\n");
  this_player()->move_player("barn#"+BROOM+"barn2");
  return 1;
}

realm() {return "NT"; }
