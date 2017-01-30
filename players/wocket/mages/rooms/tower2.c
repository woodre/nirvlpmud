#include "../defs.h"

inherit ROOM;

void reset(int arg)
{
  if(arg) return;
  set_light(1);
  short_desc=CYN+"The Misty Tower"+OFF;
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
    ROOMDIR+"tower3.c","up",
    ROOMDIR+"tower1.c","down",
    ROOMDIR+"storage.c","west",
    ROOMDIR+"dining_hall.c","east",
  });
}
