#include "../def.h"
inherit MYROOM;

int tapestry;


reset(arg) {
  tapestry=1;
  if (arg) return;
  short_desc="The King's Hoard";
  long_desc=
"     This small cave serves as the quadrian king's\n"+
"personal hoard of riches and other valuables.  For\n"+
"the most part, this consists of scraps of bright\n"+
"cloth festooned about the chamber.  Of particular\n"+
"note is a brilliant tapestry hanging from the east\n"+
"wall.\n";
  items=({
    "cloth","Pretty, bright, silk, cotton cloth in all shades and varieties",
    "tapestry","A beautiful tapestry portraying a young lady by a window.\n"+
               "You could 'take' it if wanted to"
  });
  dest_dir=({
    PATH+"Quad/cave12","west"
  });
}   
init() {
  ::init();
  add_action("search","search");
  add_action("cmd_take","take");
}
search(str) {
  write("You find nothing.\n");
  return 1;
}
cmd_take(str) {
  if(!str || str!="tapestry") { notify_fail("Take what?\n"); return 0; }
  if(!tapestry) { write("It is no longer there.\n"); return 1; }
  transfer(clone_object("/players/feldegast/obj/tapestry"),this_player());
  write("You take the tapestry down from the wall.\n");
  tapestry=0;
  return 1;
}
