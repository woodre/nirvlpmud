#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Gem Hut";
long_desc =
    "  A small round hut with four foot shelves standing along the walls.\n"+
  "A short counter stands at the back of the hut, with a wooden sign\n"+
  "that hangs on the wall behind it.  Torches line the walls at the\n"+
  "midway point and are spread apart evenly.\n";
"are spread apart evenly.\n";
   "stands at the back of the hut, with a wooden sign that hangs on the wall behind it.  Torches\n"+
  "line the walls at the midway point and are spread apart evenly.\n";

items = ({
  "hut","A small hut made of straw",
  "torches","Small, flaming torches attached to the wall",
  "counter","A short counter made of oak",
  "walls","The walls of the hut are made with bark and straw",
  "shelves","Shelves lined with gems of many colors",
  "gems","Piles of unfinished gems sitting on the shelves.\nA large pile of gems on a shelf by the window shine brightly",
  "window","A large window facing the bridge outside",
  "bridge","A long wooden bridge that disappears into the forest",
  "forest","A large gathering of trees",
 "sign","[      For - Sale      ]\n  Rubies - 2100 coins\n  Diamond - 2100 coins\n  Repair Stone (stone) - 2100 coins"
});
MOCO("/players/jaraxle/3rd/warrior/mon/melody.c"),TO);
dest_dir = ({
  "/players/jaraxle/3rd/warrior/rooms/treee2.c","out",
});

}

