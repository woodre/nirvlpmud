/*
File: 4x7.c
Creator: Feldegast @ nirvana.mudservices.com
Date: 2/1/01
Description:
  Barony of Caladon, the graveyard
*/
#include "defs.h"

inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  if(!present("shade"))
    move_object(clone_object(MON_PATH+"shade.c"),this_object());
  if(arg) return;
  x=4; y=7;
  set_light(1);
  short_desc="Graveyard";
  long_desc=
"  The surrounding hills are dotted with granite tombstones.  A cast\n\
iron fence encloses the graveyard.  To the east is the graveyard's\n\
entrance.  Near the gate is a recent grave with a fresh bouquet of\n\
flowers.\n";


  items=({
    "hills", "The surrounding hills are dotted with granite tombstones",
    "tombstones", "The tombstones are covered with various names, dates, and epithets",
    "fence", "The cast iron fence encloses the graveyard on all sides",
    "graveyard", "reflexive",
    "gate", "The gate is spread wide open for visitors to enter",
   "grave", "The grave looks like it was dug within the past few weeks.\n"+
             "A tombstone in the shape of a cross has been placed at its head",
    "tombstone", "The tombstone has some writing on it",
    "bouquet", "A collection of daisies and wildflowers",
    "flowers", "A collection of daisies and wildflowers",
  });
  dest_dir=({
    PATH+"3x7.c","west",
    PATH+"5x7.c","east",
  });
}

void init() {
  ::init();
  add_action("cmd_read", "read");
}

int cmd_read(string str) {
  if(str!="tombstone" && str!="stone" && str!="writing") {
    notify_fail("Read what?\n");
    return 0;
  }
  write("The tombstone reads:\n"+
        "  Here lies Marcus Chandian\n"+
        "  Castellan to Baron Hubert deBlood\n"); 
  say(TPN+" reads the tombstone.\n");
  return 1;
}

