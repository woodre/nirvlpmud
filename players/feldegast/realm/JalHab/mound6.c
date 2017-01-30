#include "defs.h"

inherit MNDROOM;

void reset(int arg)
{
  if(!arg) {
    short_desc=RED+"The Myrmidar Mound"+NORM;
    long_desc=
"  The tunnel widens into what would've been some sort of room had the\n\
floor not collapsed.  You can see only darkness in the hole, but a\n\
trail of packed clay leads around its edge.\n";
    items=({
      "tunnel", "The passages are perhaps six feet high, circular, and well-travelled",  
      "floor", "The floor has partially collapsed here, leaving a deep dark\n"+
               "pit and a dangerous trail",
      "hole", "The floor has partially collapsed here, leaving a deep dark\n"+
               "pit and a dangerous trail",
      "trail","The floor has partially collapsed here, leaving a deep dark\n"+
               "pit and a dangerous trail",
      "clay", "The clay has been used to reinforce the sand and slow the\n"+
              "floor's collapse",
    });
    dest_dir=({
      PATH+"mound1.c","west",
      PATH+"mound7.c","southeast",
    });
  }
  if(!present("myrmidar") && random(2))
    move_object(clone_object(MON_PATH+"myrm-worker.c"),this_object());
}
void init()
{
  ::init();
  add_action("cmd_jump","jump");
  add_action("cmd_jump","climb");
  add_action("cmd_jump","enter");
}
int cmd_jump(string str)
{
  write("You slide down the dark hole into the unknown.\n");
  say(TPN+" slides down the hole.\n");
  move_object(TP,PATH+"mound14.c");
  say(TPN+" slides down through the hole in the ceiling and lands on top of the rubble.\n");
  return 1;
}
