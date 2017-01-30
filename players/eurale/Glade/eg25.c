#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("lykker")) {
  move_object(clone_object("players/eurale/Glade/NPC/Mhooker"),TO); }
set_light(0);

short_desc = HIG+"Enchanted Glade Cave"+NORM;
long_desc =
  "  This is a small cave, large enough to stand in.  On the floor\n"+
  "is a thick layer of fragrant pine needles covered with a large\n"+
  "animal skin.  The cave entrance is out of sight and the area is\n"+
  "dark and private.\n";

items = ({
  "needles","Fresh, soft pine needles",
  "skin","A spotted, brown deer hide",
});

dest_dir = ({
  "players/eurale/Glade/eg23.c","north",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("search","search");
  add_action("north","north");
}

search() {
  write("You search the area and find nothing special.\n");
  return 1; }

north() {
  TP->move_player("north#players/eurale/Glade/eg23.c");
  ("/players/eurale/Glade/eg23.c")->set_PATRONS(0);
return 1; }
