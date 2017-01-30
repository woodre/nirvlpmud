#include "defs.h"

inherit ROOM;

int cloth;

void reset(int arg) {
  if(!present("man"))
    move_object(clone_object(MON_PATH+"hoodman.c"),this_object());
  if(arg) return;
  short_desc="The Bloated Toad";
  long_desc=
"  A heavy black cloth covers the window in this room, blocking out\n\
most of the light.  A bed with an upholstered headboard sits in the\n\
middle of the room, unused.  Two upholstered chairs sit in front of\n\
the cold fireplace.\n";
  items=({
    "cloth","It is cheap burlap cloth",
    "bed","It is neatly made and appears unused",
    "chairs","They are comfortable upholstered chairs with armrests\n"+
             "and high backs",
    "fireplace","It is cold and unlit",
  });
  dest_dir=({
    PATH+"stav3.c","north",
  });
}

void init() {
  ::init();
  add_action("cmd_pull","pull");
}

cmd_pull(str) {
  if(!str || str!="cloth") {
    notify_fail("Pull what?\n");
    return 0;
  }
  if(cloth) {
    write("You've already pulled the cloth down.\n");
    return 1;
  }
  if(present("man")) {
    write("The hooded man hisses at you, and gestures for you to\n"+
          "step away from the window.\n");
    return 1;
  }
  write("You pull aside the cloth and let light into the room.\n");
  long_desc=
    "  Light streams into the room through a leaded glass window.\n"+
    "A bed with an upholstered headboard sits in the center of the\n"+
    "room, unused.  Two upholstered chairs sit in front of the\n"+
    "cold fireplace.\n";
  cloth=1;
  return 1;
}
