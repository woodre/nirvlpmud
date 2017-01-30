#include "def.h"

inherit MYROOM;

reset(arg) {
  if(!present("may"))
    move_object(clone_object(PATH+"Npc/may"),this_object());
  if (arg) return;
  set_light(1);
  short_desc="An apartment";
  long_desc=
"     Gaudy furniture is placed around this tiny apartment with little\n\
rhyme or reason.  A bead curtain partitions off a small changing room\n\
near the couch.  A large bed is across the room, ready but unused.\n";
  items=({
    "furniture","It can only be described as gaudy.  It almost reminds\n"+
                "you of a bordello for some reason..",
    "curtain","It's made out of beads",
    "couch","A comfortable couch near the changing room",
    "bed","It's strangely large for such a small apartment"
  });
  dest_dir=({
    PATH+"alley2","down",
  });
}   
