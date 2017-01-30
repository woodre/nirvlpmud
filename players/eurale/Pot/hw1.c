#include "DEF.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Hogwarts";
long_desc =
  "  A large, open, grassy lawn surrounds this entire area.  Off to the west you\n"+
  "can see a large tree and not too far from its base a small hut. To the north\n"+
  "looms a large, stone structure which seems to be shrouded in a covering\n"+
  "mist.  To the south is a dark and frothy lake.\n";

items = ({
"lawn",
  "An expansive green with lush, thick grass growing across it almost as\n"+
  "if it were manicured",
"tree",
  "A huge tree with thick, gnarly branches hanging almost to the ground",
"branches",
  "Thick, barked limbs that taper from trunk to tip",
"hut",
  "A quaint looking hut with what appears from here to be a thatched roof",
"roof",
  "A straw roof, piled high and woven together to keep out the elements",
"structure",
  "A giant castle with 4 corner spires that reach up into the mist.  This\n"+
  "massive structure is made of solid rock and appears to be cut into the\n"+
  "side of a large cliff.  Huge double doors with ornate knockers stand a\n"+
  "the rear of the large, stone entry",
"spires",
  "Towerlike structures that reach high above the walls",
"cliff",
  "A vertical wall of rock",
"mist",
  "A bluish, green cloud that almost seems to be hiding the huge structure",
"lake",
  "Large, dark and forboding, this swirling, frothy body of water looks to\n"+
  "churned up by something big underneath its surface",
"doors",
  "Huge, shimmering doors reaching at least 25 feet in height and painted red",
});

dest_dir = ({
  "players/eurale/Pot/hw2.c","north",
  "players/eurale/Pot/hw0.c","east",
  "players/eurale/Pot/hw6.c","west",
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
