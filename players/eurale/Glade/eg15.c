#include "/players/eurale/defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);
if(!present("dhreida")) {
  move_object(clone_object("players/eurale/Glade/NPC/dhreida"),TO); }

short_desc = "A musty cave";
long_desc =
  "  Squatting down, you work your way back into a dark, musty cavern\n"+
  "dug out of the earth.  There are a few scraps of food and a couple\n"+
  "bones lying on the cavern floor.  The cavern is close and small but\n"+
  "the smell of damp earth makes one think that this is a fairly new\n"+
  "excavation.\n";

items = ({
  "cavern","A short, domed excavations dug under the glade",
  "scraps","Rotting pieces of animal flesh",
  "bones","Fresh bones from a recent meal",
});

dest_dir = ({
  "players/eurale/Glade/eg14.c","glade",
});

}

realm() { return "NM"; }

init() {
  ::init();
  add_action("search","search");
}

search() {
  write("You search the area and find nothing special.\n");
  return 1; }
