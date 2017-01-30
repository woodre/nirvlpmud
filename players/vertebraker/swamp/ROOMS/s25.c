#include "../define.h"
inherit SWAMP

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_long(
"     An apparently 'solid' wall of growth prevents you from going\n"+
"further north, and the crossroads of the swamp leads around the bends,\n"+
"going east, west, and south.  A slimy snake slithers by your ankle,\n"+
"frightening you and alerting you to the danger of the swamp yet again.\n");
   add_item(({"wall","growth"}),
      "A moss covered wall of vines and trees that extends\n"+
      " ahead of you so that you cannot cross");
   add_item("vines","Thick jungle-like vines");
   add_item("trees","Short, stringy cypress trees that emerge from the\n"+
      " depths of the swamp like little soldiers");
   add_item("snake","A small snake that dips beneath the waters");
   add_item("crossroads","You can head south, east, or west");
   add_exit(ROOM_DIR+"s26","west");
   add_exit(ROOM_DIR+"s27","east");
   add_exit(ROOM_DIR+"s46","south");
}
