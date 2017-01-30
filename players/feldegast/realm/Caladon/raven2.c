/*
File: raven2.c
Author: Feldegast
Date: 2/17/01
Description:
  Second floor of the tower of ravens in Caladon.
*/
#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc=BOLD+BLK+"Tower of Ravens"+NORM;
  long_desc=
"  A landing breaks the monotony between the flights of endless\n\
stairs.  A plush velvet carpet covers the floor and a settee is set\n\
against the inner wall.  An archway leads east into the guard room.\n";
  items=({
    "landing", "reflexive",
    "staircase", "The marble staircase spirals up into the darkness",
    "stairs", "The marble staircase spirals up into the darkness",
    "flights", "The marble staircase spirals up into the darkness",
    "marble", "The marble is black, with streaks of violet",
    "carpet", "It is a plush velvet carpet",
    "settee", "It is a couch with a back, wide enough for two people",
    "wall", "The wall is covered in a mosaic of a raven with a full moon behind it",
    "archway", "The archway is perhaps three meters high.  A ravenhead is\n"+
               "carved into the arch",
    "room", "Perhaps you should go inside and take a look",    
  });
  dest_dir=({
    PATH+"raven4.c", "up",
    PATH+"raven1.c", "down",
    PATH+"raven3.c", "east",
  });
}
