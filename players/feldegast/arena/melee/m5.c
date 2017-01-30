#include "def.h"

inherit AROOM;

reset(arg) {
  ::reset(arg);
  if(!present("death gate"))
    move_object(clone_object(PATH+"death_gate"),this_object());
  if(arg) return;
  set_light(1);
  short_desc=BOLD+"Ruins"+NORM;
  long_desc=
"  Stone walls and pillars are all that remain of what was once some\n"+
"sort of temple or palace that stood on top of this hill.  To the east\n"+
"the land becomes flatter and dotted with trees.  To the north the\n"+
"land plunges down into a valley, and to the west are more hills.\n";  
  items=({
    "walls","Ancient graffitti in some lost language covers the walls",
    "pillars","Tall fluted columns that once supported the rubble that is now\n"+
              "strewn carelessly around",
    "hill","A picturesque green hill which borders on several different kinds\n"+
           "of terrain",
    "trees","You think there's a forest, but you can't see it because of\n"+
            "all the trees",
    "forest","I dream of a scottish lass who drank me under the table one eve",
    "valley","'Gosh, this water tastes awfully dry'",
    "hills","'Rashel, I need sexsh as much as you do'",
  });
  dest_dir=({
    PATH+"m2b","north",
    PATH+"m4","west",
    PATH+"m6","east",
    PATH+"m8","south"
  });
}
long(str) {
  if(str=="forest") view_room(PATH+"m6");
  else if(str=="valley") view_room(PATH+"m2b");
  else if(str=="hills") view_room(PATH+"m4");
  else ::long(str);
}
