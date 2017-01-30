#include "/players/feldegast/defines.h"
inherit ROOM;
reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc=BOLD+"A jungle ruin"+NORM;
  long_desc=
"     You've found some ruins in the middle of the jungle.  It\n"+
"appears to have been a marketplace of some sort, but now it\n"+
"lacks any merchants or vendors it may've once had.\n";
  items=({
    "ruins","Weathered marble, cobblestones, and walls are all that remain"
  });
  dest_dir=({
    "/players/feldegast/island/jungle/jungle25","north",
    "/players/feldegast/island/jungle/jungle27","west",
    "/players/feldegast/island/jungle/jungle30","south"
  });
}
init() {
  ::init();
  add_action("search","search");
}
int search(string str) {
  write("You find an old barrel of red herrings.\n");
  return 1;
}
