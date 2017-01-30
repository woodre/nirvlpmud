#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(!present("armorer"))
    move_object(clone_object(MON_PATH+"goldcloak3.c"),this_object());
  if(arg) return;
  set_light(1);
  short_desc="Tower of the Righteous";
  long_desc = 
"  This is the tower's armory.  Various pieces of armor and several\n"+
"types of weapons are kept locked up in grilled cages that line\n"+
"every single wall.  At the end of the room, a little workshop is\n"+
"set up with a forge and hammer for repairing weapons and armor.\n";
  items=({
    "armor", "Unfortunately, they're all locked up where you can't get\n"+
             "to them",
    "weapons", "Unfortunately, they're all locked up where you can't get\n"+
               "to them",
    "cages", "The cages are made out of thin steel bars",
    "workshop", "A neat little workshop for repairing Goldcloak weapons\n"+
                "and armor",
  });
  dest_dir=({
    PATH+"barrack3.c","east",
    PATH+"barrack5.c","up",
  });
}

