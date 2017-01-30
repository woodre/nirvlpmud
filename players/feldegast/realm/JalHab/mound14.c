#include "defs.h"

inherit MNDROOM;

void reset(int arg)
{
  if(arg)return;
  short_desc=RED+"The Myrmidar Mound"+NORM;
  long_desc=
"  This is an airpocket deep inside the earth.  Dust and sand chokes\n\
you, making it difficult to breathe.  High above you, you can see the\n\
edge of the hole that you're in.  The dirt seems looser to the south.\n";
  items=({
    "hole", "You don't see any way to get back up",
    "dust", "The more you stare at it, the more it gets into your eyes",
    "sand", "It sifts down into the hole",
  });
}
void init(int arg)
{
  add_action("cmd_south","south");
}

int cmd_south(int arg)
{
  write("You push south through the dirt.\n");
  say(TPN+" pushes south through the dirt.\n");
  move_object(TP,PATH+"mound17.c");
  command("look",TP);
  say(TPN+" comes out of the wall to the north.\n");
  return 1;
}
