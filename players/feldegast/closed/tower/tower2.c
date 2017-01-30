#include "defs.h"

inherit ROOM;

int locked;

reset(arg) {
  locked=1;
  if (arg) return;
  set_light(1);
  short_desc="A marble staircase";
  long_desc=
"  You are on a huge marble staircase running up the center of the\n"+
"Crystal Tower.  There are strong oak doors to the east and to\n"+
"the west.\n";
  items=({
  });
  dest_dir=({
    PATH+"tower3","up",
    PATH+"seds_room","north",
    PATH+"bedroom","west",
    "/players/feldegast/closed/tower/study","east",
    "/players/feldegast/closed/tower/armory","south",
    "/players/feldegast/closed/tower/tower1","down"
  });
}

init() {
  ::init();
  add_action("cmd_south","south");
  add_action("cmd_lock","lock");
}
cmd_south() {
  if(locked) {
    write("That door is locked.\n");
    return 1;
  }
}
cmd_lock() {
    write("You "+(locked?"unlock":"lock")+" the door to the south.\n");
    locked=!locked;
  return 1;
}
