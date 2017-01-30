  /* donation room  */

#include "/players/eurale/closed/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
  if (arg) return;

set_light(0);
short_desc = "Vampire Donation Room";
long_desc =
  "A wide, stone shelf lines this entire room.  The solid stone floor\n"+
  "echoes not only the footsteps of members entering to leave spare gear\n"+
  "for the less fortunate but also those of the needy coming here with\n"+
  "hopes of finding something that they can use.  Engraved into the\n"+
  "floor is some lettering.\n";

items = ({
  "shelf","A wide, grey shelf capable of holding many items",
  "floor","Cut through the solid rock and worn smooth by many feet",
  "lettering","It resembles a readable warning cut into the floor",
});


dest_dir = ({
  "players/eurale/VAMPIRES/RMS/wing_room.c","east",
});

no_castle_flag = 1;
}

realm() { return "NT"; }

is_castle() { return 1; }

clean_up() { return 0; }

init() {
  ::init();
  add_action("read","read");
}

read(str) {
if(!str) { write("Read what?\n"); return 1; }
if(str == "lettering" || str == "warning") {
  write("\n"+
   "A rectagular border surrounds the words:\n"+
   HIR+"   'Take what you need, NEED what you take!'\n"+NORM);
  return 1; }
}

down() {
if(!present("efangs",TP)) {
  write("A strange force prevents you from going down...\n");
  return 1; }
TP->move_player("down#players/eurale/VAMPIRES/RMS/basement.c");
return 1;
}
