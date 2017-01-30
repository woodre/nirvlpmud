#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(!present("chest"))
    move_object(clone_object(OBJ_PATH+"chest.c"),this_object());
  if(!present("damsel"))
    move_object(clone_object(MON_PATH+"damsel.c"),this_object());
  if(!present("brigand"))
    move_object(clone_object(MON_PATH+"brigand9.c"),this_object());
  if(arg) return;
  set_light(1);
  short_desc="Brigand Cave";
  long_desc=
"  This cave is decorated with the tasteful furniture of an upper\n"+
"class home.  A thick carpet covers the floor, and a four-posted bed\n"+
"is in the middle of the room.  A pair of vases sit on nightstands\n"+
"on either side of it.\n";
  items=({
    "furniture", "A carpet, a bed, and two nightstands",
    "carpet", "A plush red carpet",
    "bed", "It is a strongly built wooden bed with a soft feather mattress\n"+
           "and silk sheets",
    "vases", "They appear to be cheap knock offs.  Probably not worth much",
    "nightstands", "A pair of mahogany tables sit on either side of the bed",
  });
  dest_dir=({
    PATH+"rocks5.c","southwest",
  });
}

