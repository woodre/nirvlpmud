#include "../def.h"
inherit MYROOM;
reset(arg) {
  int i;
  if(!present("quadrian")) {
    for(i=0;i<=random(3);i++) {
      move_object(clone_object("/players/feldegast/mon/quadsmith"));
    }
  }
  if (arg) return;
  set_light(1);
  short_desc="An underground smithy";
  long_desc=
"     In the center of this smoky cave is a mighty forge\n"+
"where, for generations, Quadrians have forged their silver\n"+
"weapons.  In the north part of the cave is the nominal\n"+
"living space of the apprentice blacksmiths, and beyond that,\n"+
"the alcove where the master blacksmith resides.\n";
  items=({
    "forge","The quadrian blacksmiths pound shape into metal here",
    "living space","A few cots and blankets",
    "alcove","A ragged sheet of cloth obscures the entrance"
  });
  dest_dir=({
    PATH+"Quad/cave7","north",
    PATH+"Quad/cave5","south"
  });
}   
init() {
  ::init();
  add_action("block","north");
  add_action("search","search");
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
