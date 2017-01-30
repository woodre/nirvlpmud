/*
File: raven3.c
Author: Feldegast
Date: 2/17/01
Description:
  Second floor of the tower of ravens in Caladon.  Guard room.
*/
#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(!present("danica"))
    move_object(clone_object(MON_PATH+"danica.c"),this_object());
  if(arg) return;
  set_light(1);
  short_desc=BOLD+BLK+"Tower of Ravens"+NORM;
  long_desc=
"  This is a large rectangular room with an archway leading west.\n\
In the eastern half of the room are a pair of bunk beds with lockers\n\
at the foot of each one.  Closer to the door there is a mahogany\n\
desk and a pair of weapon racks.\n";
  items=({
    "room", "reflexive",
    "archway", "The archway is perhaps three meters high.  A ravenhead is carved\n"+
               "into the arch",
    "beds", "The bunk beds are sturdy and well-made.  Each one is placed against\n"+
            "a wall on opposite sides of the room",
    "bunks","The bunk beds are sturdy and well-made.  Each one is placed against\n"+
            "a wall on opposite sides of the room",
    "lockers", "These appear to be simple wooden foot lockers for keeping everyday\n"+
               "junk in",
    "desk", "This appears to be a simple work desk.  It is neat, but rarely used",
    "racks", "The weapon racks appear to be empty right now",
  });
  dest_dir=({
    PATH+"raven2.c", "west",
  });
}

void init() {
  ::init();
  add_action("cmd_open", "open");
}

int cmd_open(string str) {
  if(str=="locker" || str=="lockers") {
    write("You open the lockers but find nothing of interest inside.\n");
    return 1;
  }
}

