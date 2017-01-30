/*
File: raven1.c
Author: Feldegast
Date: 2/17/01
Description:
  First floor of the tower of ravens in Caladon.
*/
#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(!present("ravenguard"))
    move_object(clone_object(MON_PATH+"ravenguard.c"),this_object());
  if(!present("ravenguard 2"))
    move_object(clone_object(MON_PATH+"ravenguard.c"),this_object());
  if(arg) return;
  set_light(1);
  short_desc=BOLD+BLK+"Tower of Ravens"+NORM;
  long_desc=
"  This appears to be some sort of entry hall.  An open metal door\n\
leads back outside.  Beside the door are a couple of guard posts.  A\n\
marble staircase spirals up into the darkness.  Behind the staircase\n\
is a metal grate.\n";
  items=({
    "hall", "reflexive",
    "door", "On this side, it appears to be a simple metal door",
    "posts", "These niches look like nice spots for guards to stand",
    "niches", "These guards look like nice stands for posts to spot",
    "staircase", "The marble staircase spirals up into the darkness",
    "marble", "The marble is black, with streaks of violet",
    "grate", "You can't open the grate from this side.  It seems to lead into darkness",
  });
  dest_dir=({
    PATH+"1x8.c", "out",
    PATH+"raven2.c", "up",
  });
}

void init() {
  ::init();
  add_action("cmd_open", "open");
}

int cmd_open(string str) {
  if(str=="grate") {
    write("You can't open the grate from this side.\n");
    return 1;
  }
}
