#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(!present("pelin"))
    move_object(clone_object(MON_PATH+"sir_pelin.c"),this_object());
  if(arg) return;
  set_light(1);
  short_desc=BOLD+BLK+"Castle Magnarn"+NORM;
  long_desc=
"  The crenelated battlements of the castle are crumbling in places\n\
here, but the view of the desert below remains awe-inspiring.  An\n\
archway leads back into the castle.\n"; 
  items=({
    "battlements", "The wall of the castle follows closely to the edge\n"+
                   "of the mesa.  They are crenelated and constructed\n"+
                   "of sandstone",
    "view", "You can see far across the desert from here",
    "desert", "You can see far across the desert from here",
    "archway", "It leads back into the castle",
  });
  dest_dir=({
    PATH+"castle4.c","west",
  });
}
