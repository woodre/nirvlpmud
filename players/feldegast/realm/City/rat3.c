/*
File: rat3.c
Author: Feldegast
Date: 11/02/98
Revised: 03/23/02
Description:
  Secret entrance to the rat's nest.
*/

#include "defs.h"

inherit ROOM;

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="A rooftop";
  long_desc=
"  This is the rooftop of a fair sized building in the city of\n\
Calador.  A wooden plank leads to the building to the south, while\n\
a wooden staircase appears to be the only way down into the building.\n";
  items=({
    "rooftop",   "It is a flat tar surface with a slight slope marred only\n"+
                 "by a stairwell leading down into the building",
    "plank",     "It looks sturdy enough to hold your weight",
    "staircase", "It appears to have been repaired recently, unlike the\n"+
                 "rest of this area",
  });
  dest_dir=({
    PATH+"rat2","back",
    PATH+"rat4","down"
  });
}

init() {
  ::init();
  add_action("cmd_jump","jump");
  add_action("smell","smell");
}

smell() {
  write("The air up here is relatively fresh.\n");
  return 1;
}

cmd_jump(str) {
  write("It is too far to jump to any other buildings.\n");
  return 1;
}
