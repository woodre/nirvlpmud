#include "defs.h"

inherit MAPROOM;

void reset(int arg)
{
  if(arg) return;
  set_light(1);
  short_desc="P'kalian Village";
  long_desc=
"  The soil seems less grainy and more substantial here.  Between two\n\
hills lies a peaceful village constructed mostly out of sandstone.  The\n\
buildings are all arranged in a circle, around something that you\n\
can't see from here.\n";
  items=({
    "village","A peaceful village constructed mostly out of sandstone.\n"+
              "You could probably 'enter' it'",
  });
  dest_dir=({
    "blank","north",
    "blank","west",
    "blank","east",
    "blank","south",
  });
}

void init()
{
  ::init();
  add_action("cmd_enter","enter");
}

int cmd_enter(string str)
{
  notify_fail("Enter what?\n");
  if(!str || (str!="village" && str!="town")) return 0;
  say(TPN+" enters the village.\n");
  move_object(TP,PATH+"pwell.c");
  write("You enter the village.\n");
  say(TPN+" arrives.\n");
  command("look",TP);
  return 1;
}
