#include "defs.h"

inherit ROOM;

void reset(int arg)
{
  if(arg) return;
  set_light(1);
  short_desc=TOWER;
  long_desc=
"  The great marble staircase ascends the misty tower, seeming to\n\
spiral up into infinity.  The staircase seems to pause here to catch\n\
its breath upon a landing.  To the east is an archway through which\n\
you can see many people eating and chatting.  To the west is a storage\n\
room.\n";
  items=({
    "staircase","A great staircase constructed from green and blue marble",
    "archway","A simple archway constructed of granite stones",
  });
  dest_dir=({
    ROOMPATH+"tower3.c","up",
    ROOMPATH+"tower1.c","down",
    ROOMPATH+"storage.c","west",
    ROOMPATH+"dining_hall.c","east",
  });
}
