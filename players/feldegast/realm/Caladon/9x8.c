/*
File: 9x8.c
Creator: Feldegast @ nirvana.mudservices.com
Date: 2/13/02
Description:
  Barony of Caladon
*/
#include "defs.h"

inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  x=9; y=8;
  set_light(1);
  short_desc=AREANAME;
  long_desc=
"  The land rises steeply here and finally ends in an impassable cliff\n\
to the east.  Beyond the cliff are the snowcapped peaks of the Spine\n\
of Allandria.  A crack in the cliff wall leads into darkness.  The\n\
terrain to the west is too rocky to traverse.\n";
  items=({
    "spine", "Many miles to the east, you see the snow-capped mountain range\n"+
             "known as the Spine of Allandria",
    "cliff", "To the east is an impassable cliff.  A horizontal crack in the rock\n"+
             "leads into darkness",
    "crack", "A horizontal crack in the cliff wall leads into darkness",
    "wall",  "A horizontal crack in the cliff wall leads into darkness",
    "darkness", "A horizontal crack in the cliff wall leads into darkness",
    "terrain", "The terrain to the west is too rocky to traverse",
  });

  dest_dir=({
    PATH+"9x9.c","north",
  });
}

void init()
{
  ::init();
  add_action("cmd_enter", "enter");
}

int cmd_enter(string str)
{
  if(str!="darkness" && str!="crack" && str!="cave")
  {
    notify_fail("Enter what?\n");
    return 0;
  }

  say(TPN+" enters the cave.\n");
  write("You enter the cave.\n");
  move_object(TP, PATH+"cave1.c");
  command("look", TP);
  say(TPN+" enters the cave.\n");
  return 1;
}
