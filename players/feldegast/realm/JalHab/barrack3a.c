#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(arg) return;
  set_light(0);
  short_desc="Tower of the Righteous";
  long_desc = 
"  This appears to be some sort of crawlspace in the tower's\n"+
"woodwork with a ladder leading up and down the length of the\n"+
"tower and carefully disguised doors at regular intervals.\n";
  items=({
    "ladder", "The ladder is poorly maintained.  It doesn't seem to have\n"+
              "been used recently",
    "doors", "The doors are spaced at regular intervals on the ladder",
  });
  dest_dir=({
    PATH+"barrack2.c","one",    
    PATH+"barrack3.c","two",
    PATH+"barrack6.c","three",
  });
}

void init() {
  ::init();
  add_action("cmd_one", "one");
  add_action("cmd_out", "out");
}

int cmd_out(string str) {
  write("You fumble around until you find your way out.\n");
  TP->move_player("out#"+PATH+"barrack3");
  return 1;
}

int cmd_one(string str) {
  write("\nThe door swings open behind the hearth.  When you step\n"+
        "out of the hearth, the door swings closed behind you,\n"+
        "leaving no way to open it.\n\n");
  return 0;
}

