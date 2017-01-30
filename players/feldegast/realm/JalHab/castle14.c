#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(arg) return;
  move_object(clone_object(WEP_PATH+"summer.c"),this_object());
  set_light(1);
  short_desc=BOLD+BLK+"Castle Magnarn"+NORM;
  long_desc=
"  This is a deep, dank pit perhaps twenty feet deep and\n"+
"five feet in diameter.\n";
  items=({
  });
  dest_dir=({
    PATH+"castle13.c","up",
  });
  no_clean = 1;
}
