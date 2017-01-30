#include "DEFS.h"
inherit "room/room";
int TREASURE;

reset(arg) {
  if(arg) return;
if(!present("histachii")) {
  move_object(clone_object("/players/eurale/Lab/NPC/histachii.c"),TO); }
set_light(0);
TREASURE = 1;

short_desc = "Labyrinth";
long_desc =
  "  Bones litter the floor.  Pieces of adventurer equipment lay dented\n"+
  "and rusted.  A pile of dirty rags rests against the back wall.  The\n"+
  "stench of rotting meat drifts in the stagnant air.\n";

items = ({
  "bones","Severed and broken bones, devoid of meat, possibly from humans",
  "floor","Solid stone with dark stains",
  "stains","They appear to be fresh and tinted red.. blood, perhaps?",
  "pile","The remnants of what used to be clothing",
  "rags","The remnants of what used to be clothing",
  "wall","Solid stone and slightly curved from side to side",
});

dest_dir = ({
  "players/eurale/Lab/l20.c","west",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("Search","search");
}

Search(str) {
object coins;
if(!str) { write("What?\n"); return 1; }
if(str == "rags" || str == "pile") {
  if(TREASURE == 1) {
    coins = 1 + random(20);
    write("You search the "+str+" and find "+coins+" coins.\n");
    TP->add_money(coins);
    TREASURE = 0;
    return 1; }
write("You search the "+str+" and find nothing of interest.\n");
return 1; }
}
