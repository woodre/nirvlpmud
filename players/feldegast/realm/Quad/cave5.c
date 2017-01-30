#include "../def.h"
inherit "/players/feldegast/std/room";
reset(arg) {
  int i;
  if(!present("quadrian")) {
    for(i=0;i<=random(5);i++) {
      move_object(clone_object("/players/feldegast/mon/quadpeon"));
    }
    if(!random(3)) {
      move_object(clone_object("/players/feldegast/mon/quadsmith"));
    }
  }
  if (arg) return;
  set_light(1);
  short_desc="A cavern";
  long_desc=
"    Sounds echo off of the walls of this roomy cavern.  It\n"+
"appears to be some sortof central gathering area for the\n"+
"subterranean residents of this network of caves.  In the\n"+
"middle of the cavern is a central firepit with a natural\n"+
"chimney to prevent the smoke from getting too thick.\n";
  items=({
    "walls","The walls appear to be granite",
    "firepit","A natural depression in the rock that is now filled with ashes",
    "chimney","A small fissure in the ceiling of the cave"
  });
  dest_dir=({
    PATH+"Quad/cave6","north",
    PATH+"Quad/cave3","west",
    PATH+"Quad/cave4","east"
  });
}   
init() {
  ::init();
  add_action("search","search");
}
search(str) {
  write("You notice many tracks of some sort of biped.\n");
  return 1;
}
