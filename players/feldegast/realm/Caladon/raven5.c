/*
File: raven5.c
Author: Feldegast
Date: 2/25/01
Revised: 10/25/01
Description:
  Third floor of the tower of ravens in Caladon.
Clarisse's room.
*/
#include "defs.h"

inherit ROOM;

void reset(int arg) {
  object door;
  if(!present("clarise"))
    move_object(clone_object(MON_PATH+"clarise.c"), this_object());
  if(arg) return;
  set_light(1);
  short_desc=BOLD+BLK+"Tower of Ravens"+NORM;
  long_desc=
"  This is a well-appointed bedroom.  A cool wind breezes into this\n\
room through a window.  The wind blows about the red cloth that\n\
covers the canopied bed near the fireplace.  Across from the bed is\n\
a mahogany table with a guttering red candle.  There is a door in the\n\
eastern wall.\n";

  items=({
    "bedroom",   "reflexive",
    "wind",      "You can't quite make it out.  Its almost as though the wind were invisible",
    "cloth",     "It canopies the bed",
    "fireplace", "It is a simple fireplace made out of red bricks.  It provides abundant heat",
    "bed",       "It is large bed with silk sheets and a purple canopy.  It appears\n"+
                 "to be well-used",
    "table",     "It is a short mahogany table",
    "candle",    "A candle made out of red wax sits upon the mahogany table.  Its flame\n"+
                 "gutters fitfully in the wind",
  });

  dest_dir=({
    PATH+"raven4.c", "east",
  });
  door=clone_object(DOOR);
  door->add_id("door");
  door->add_id("steel-bound door");
  door->set_open_desc("It is a steel-bound door made out of oak.\n");
  door->set_close_desc("It is a steel-bound door made out of oak.\n");
  door->set_destination(PATH+"raven4.c");
  door->set_exit("east");
  door->set_open(0);
  door->set_locked(0);
  door->set_key("clarisse_door");
  door->set_trapped(1);
  door->set_trap_dmg(20);
  door->set_trap_msg("A needle pops out of the door's lock and jabs you in the hand.\n");
  door->set_partner("door", PATH+"raven4.c");
  move_object(door,this_object());
}

