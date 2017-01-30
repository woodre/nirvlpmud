#include "def.h"

inherit MYROOM;

reset(arg) {
  if(!present("sleep"))
    move_object(clone_object(PATH+"Npc/mrsleep"),this_object());
  if (arg) return;
  set_light(0);
  short_desc=BLU+"Underworld"+NORM;
  long_desc=
"     The labyrinthine depths of this underworld are filled with\n\
technological wonders beyond humanity's ability to recreate.  A\n\
shadowy corridor leads further into the dark and an elevator leads\n\
back up to the city streets.\n";
  items=({
    "wonders","These corridors appear to riddle the framework of some\n"+
              "gargantuan machine whose purpose remains unknown",
    "corridor","The corridor leads through the great machine",
    "elevator","The \"elevator\" is really just a simple platform with guard rails\n"+
               "that follows a track that leads back up to the surface"
  });
  dest_dir=({
    PATH+"ug2","north",
    PATH+"alley3","up"
  });
}   
