#include "def.h"
inherit MYROOM;
reset(arg) {
  if(!present("husslebeck"))
    move_object(clone_object(PATH+"Npc/husslebeck"),this_object());
  if (arg) return;
  set_light(1);
  short_desc="Squad room";
  long_desc=
"     Desks fill this crowded squad room as phones ring and police\n\
officers rush about.  To the north and south are offices partitioned\n\
off from the main room.\n";
  items=({
    "desks","Crowded desks with blotters and lots of pens",
    "phones","Old-fashioned rotary dial phones for the most part"
  });
  dest_dir=({
    PATH+"w-office","north",
    PATH+"street6","west",
    PATH+"b-office","south"
  });
}   
