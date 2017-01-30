#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(!present("reid"))
    move_object(clone_object(MON_PATH+"sir_reid.c"),this_object());
  if(arg) return;
  set_light(1);
  short_desc=BOLD+BLK+"Castle Magnarn"+NORM;
  long_desc=
"  At one time, this must've been a chapel or meditation chamber of\n\
some sort.  Unfortunately, scavengers have removed the decorations\n\
and furnishings.  Nothing is left to indicate to what deity or\n\
principle it was dedicated.\n";
  items=({
    "decorations", "There aren't any",
    "furnishings", "There aren't any",
  });
  dest_dir=({
    PATH+"castle4.c","south",
  });
}
