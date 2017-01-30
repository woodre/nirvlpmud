inherit"/room/room";
#include <ansi.h>
 
reset(arg)
{
::reset(arg);
  set_light(1);
  short_desc = "An Ancient"+HIK+" Cave "+NORM+"of "+HIR+"Old"+NORM;
  long_desc = "  A small deep dark cave where the darkness seems to go on forever.\n\
  A eerie cold wind gushes from the back of the cave and echos of movement can\n\
  be heard bouncing off the cave walls. Only the bravest of adventures travel to\n\
  the darkest depths of the cave. Around the opening of the cave are slashes and\n\
  deep gouges in the stone. The atmosphere outside of the cave is very silent and\n\
  no movement or life can be seen\n";
  items = 
  ({
  "gouges",
    "A bunch of spots where weapons have seemed to hit the cave wall.",
    "slashes",
    "Hard objects seem to have made this slashes into the stone wall.",
    "darkness",
    "A darkness that seems to go into the caves forever.",
  });
    dest_dir=({
  ,
  });
  } 