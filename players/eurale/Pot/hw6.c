#include "DEF.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Hogwarts";
long_desc =
  "  A wooden hut lies immediately to the west.  To the north is a large, gnarly\n"+
  "tree with huge branches.  The manicured lawn stretches off to the east where\n"+
  "a huge, castle-looking structure stands.  You can also see a large lake off\n"+
  "to the southeast.\n";

items = ({
  "lawn","A huge, grassy knoll that stretches forever, it seems",
  "castle","Hogwart's school of magic",
  "structure","A castle-like building with 4 spires at the corners",
  "lake","A dark, forboding body of water",
  "hut","A small, wooden hut with a solid, wooden door and a large window",
  "door","Two inch thick wood with large metal hinges",
  "window","A four pane window looking out over the grassy knoll",
  "tree","A huge willow tree with lots of huge limbs.  It almost seems to be\n"+
         "protecting the woods behind it",
  "limbs","Large branches with big knot holes.  The limbs looked scarred",
  "branches","Knotty limbs with scarpes and cuts",
});

dest_dir = ({
  "players/eurale/Pot/hw8.c","north",
  "players/eurale/Pot/hw7.c","enter",
  "players/eurale/Pot/hw1.c","east",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("Search","search");
}

Search(str) {
if(!str) { write("You search aimlessly but to no avail.\n"); return 1; }
write("You search the "+str+" but find nothing special.\n");
say(capitalize(TPRN)+" searches the "+str+" but finds nothing.\n");
return 1;
}
