#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc="Hallway";
  long_desc=
"  Light streams through a window at the end of this hallway.  In\n"+
"front of the window is a table with a potted fern on it.  At the\n"+
"end of the hall opposite the window the stairs run back down.  In\n"+
"the middle of the hall, two doors face each other.\n";
  items=({
    "window","The window faces down onto the plaza",
    "table","There is a fern on it",
    "fern","It looks wilted, which ruins any decorative\n"+
           "effect that might've been intended",
    "doors","They face each other across the hallway",
    "stairs","They lead down",
  });
  dest_dir=({
    PATH+"stav2.c","down",
    PATH+"stav4.c","north",
    PATH+"stav5.c","south",
  });
}

    