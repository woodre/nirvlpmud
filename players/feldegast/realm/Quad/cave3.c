#include "../def.h"
inherit MYROOM;
reset(arg) {
  if(!present("quadrian")) {
    int i;
    for(i=0;i<=random(3);i++) {
      move_object(clone_object("/players/feldegast/mon/quad"));
    }
  }
  if (arg) return;
  short_desc="A dim tunnel";
  long_desc=
"    A natural fissure forms a narrow tunnel through the rock\n"+
"that leads north and south into shadows.  You hear bats above\n"+
"your head, but you can't make out the ceiling no matter how\n"+
"hard you try.  A large crack in the limestone wall leads east.\n";
  items=({
    "rock","Limestone and granite walls surround you",
    "shadows","No matter how hard you try, you cannot penetrate the shadows",
    "ceiling","You can't make it out",
    "crack","A natural crack that has been carved wider",
    "wall","The walls of the fissure are about five feet apart"
  });
  dest_dir=({
    PATH+"Quad/cave11","north",
    PATH+"Quad/cave5","east",
    PATH+"Quad/cave1","south"
  });
}   
init() {
  ::init();
  add_action("block","north");
  add_action("search","search");
}
search(str) {
  write("You notice many tracks of some sort of biped.\n");
  return 1;
}
block() {
  if(present("quadrian")) {
    if(random(this_player()->query_stat("ste"))<20) {
      write("The quadrian prevents you from going that way.\n");
      return 1;
    }
    else {
      write("You slip past the quadrian.\n");
      return 0;
    }
  }
  return 0;
}
