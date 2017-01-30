#include "/players/feldegast/defines.h"
#include "../def.h"
inherit MYROOM;
reset(arg) {
  if(!present("king"))
    move_object(clone_object("/players/feldegast/mon/quadking"));
  if (arg) return;
  set_light(1);
  short_desc="The Throne Room";
  long_desc=
"    This cave was once a small waterfall in an underground\n"+
"stream, making for unusual rock formations carved out of the\n"+
"limestone that forms these caves.  A protrusion in the middle\n"+
"of the cave has been carved into a magnificent throne from\n"+
"which the ruler of these caves may lay down his proclamations.\n"+
"A dark passage behind the throne leads east.\n";
  items=({
    "formations","The bottom of the cave is like a smooth bowl with\n"+
                 "smooth stalagmites protruding from the floor",
    "protrusion","It has been carved into a magnificent throne",
    "throne","The throne is a piece of the cave floor, carved into\n"+
             "a suitably majestic chair"
  });
  dest_dir=({
    PATH+"Quad/cave11","south"
  });
}   
init() {
  ::init();
  add_action("search","search");
  add_action("cmd_east","east");
}
search(str) {
  write("You find nothing.\n");
  return 1;
}
cmd_east() {
  if(present("quadrian")) {
    write("King Tetros blocks the entrance.\n");
    return 1;
  }
  TP->move_player("east#"+PATH+"Quad/cave13");
  return 1;
}
