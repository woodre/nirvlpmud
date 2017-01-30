/*
File: amber1.c
Author: Feldegast
Date: 04/09/02
Description:
  Amber street
*/

#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if (arg) return;
  set_light(1);
  short_desc=AREANAME;
  long_desc=
"  Amber street descends at a steap angle down from the hills to the\n\
river to the south.  The houses that line the street are all well-\n\
made, but many have fallen into disrepair.  Amber street was once a\n\
prosperous neighborhood, but now has a sense of decay about it.\n";
  items=({
    "amber street", "reflexive",
    "hills", "The street descends at a steep angle and with few zig-zags down\n"+
             "the hills to the river to the south",
    "houses", "Many of the houses have fallen into disrepair, but none of them\n"+
              "appear to be of interest to you",
    "neighborhood", "The neighborhood is scarcely inhabited and the few inhabitants scurry\n"+
                    "quickly about their business",
  });
  dest_dir=({
    PATH+"marble7.c", "north",
    PATH+"amber2.c","south"
  });
}   
