#include "defs.h"

inherit MAPROOM;

void reset(int arg)
{
  if(arg)return;
  set_light(1);
  short_desc="The Myrmidar Mound";
  long_desc=
"  The ground here becomes rocky and treacherous, and finally swells up,\n\
like a pregnant woman into an artificial mound.  At the top of the mound,\n\
a cave leads into the darkness.\n";
  dest_dir=({
    "blank","north",
    "blank","west",
    "blank","east",
    "blank","south",
  });
  items=({
    "ground", "It is rocky and treacherous",
    "mound", "It is about fifty meters tall and perfectly rounded",
    "cave", "The cave leads into the mound",
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
  if(!str || (str!="cave" && str!="mound")) return 0;
  say(TPN+" enters the mound.\n");
  move_object(TP,PATH+"mound1.c");
  write("You enter the mound.\n");
  say(TPN+" steps in.\n");
  command("look",TP);
  return 1;
}
