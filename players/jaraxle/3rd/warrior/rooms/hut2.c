#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(2);

short_desc = "Hut";
long_desc =
        "  The trunk is shaped lika a hollow cylinder.  There are two\n"+
        "very tall torches standing proudly at each end of a long counter.\n"+
        "An assortment of boxes and crates are placed scattered behind\n"+
        "the counter.\n";
items = ({
  "trunk","A hollowed out tree trunk",
  "counter","A long dark-wood counter.\nThere is a sign behind it you can "+HIW+"look at"+NORM+"",
 "torches","Two large torches standing about four feet high.\nFlames flick violently from the tips of the torches",
  "boxes","Many boxes of different sizes, some as large as people",
  "crates","Large crates about five feet in length. (Or are they coffins?)",
  "flames","Flames with a blueish hue lighting the hut",
  "sign","Niala's Shopping Hut\n[ "+HIY+"Buy"+NORM+" ] [ "+HIG+"Sell"+NORM+" ] [ "+MAG+"List"+NORM+" ]",
});

MOCO("/players/jaraxle/3rd/warrior/mon/shopkeep.c"),TO);
dest_dir = ({
  "/players/jaraxle/3rd/warrior/rooms/treew3.c","out",
});

}

