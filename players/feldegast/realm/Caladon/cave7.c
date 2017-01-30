/*
File: cave7.c
Creator: Feldegast @ nirvana.mudservices.com
Date: 2/24/02
Description:
  Barony of Caladon
*/
#include "defs.h"

inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  if(!present("spider") && !random(2))
    move_object(clone_object(MON_PATH+"spiderw"), this_object());
  if(!present("spider 2") && !random(2))
    move_object(clone_object(MON_PATH+"spiderh"), this_object());
  if(arg) return;
  set_light(0);
  short_desc=AREANAME;
  long_desc=
"  This is a cave deep beneath the earth.  The cave walls are jagged\n\
and filled with nooks and crannies where evil skittery things reside.\n\
Thick, cottony webs fill the cave from wall to wall.\n";
  items=({
    "cave", "The cave is approximately twenty meters across and several\n"+
            "meters high",
    "earth", "It surrounds you on all sides",
    "walls", "They are jagged and filled with nooks and crannies where evil\n"+
             "skittery things reside",
    "webs", "The webs are thick and sticky.  You'd hate to meet what made them",
    "wall", "They are jagged and filled with nooks and crannies where evil\n"+
            "skittery things reside",
  });

  dest_dir=({
    PATH+"cave6.c", "up",
    PATH+"cave8.c", "south",
  });
}

void init()
{
  ::init();
  add_action("cmd_block", "south");
}

int cmd_block(string str)
{
  if(present("spider"))
  {
    write("A spider crouches by the tunnel to the south, blocking the way.\n");
    return 1;
  }
}
