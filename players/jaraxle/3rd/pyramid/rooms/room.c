#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(-1);

long_desc =
        ""+BLK+""+BOLD+"  The grand foyer of a great pyramid.  Cold sand covers the\n"+
        "entire floor of the pyramid.  Columns line the sides of this\n"+
        "area creating a hallway through the center of the pyramid. The\n"+
        "ceiling rises above about ten feet high.  The walls and ceiling\n"+
        "have been built out of stones made from hardened clay."+NORM+"\n";

items = ({
  "foyer","A large entryway into the Dark Pyramid",
  "clay","Hard packed mud, dried to a solid brick",
  "stones","Hard packed mud, dried to a solid brick",
  "pyramid","A large structure made from clay stone",
  "area","The opening of the pyramid",
  "sand","The cold sand is very smooth to the touch, and light tan in color",
  "floor","The ground of the pyramid is covered with sand",
  "ceiling","The top of the pyramid, it is high above about twenty feet",
  "columns","Thick columns of stacks clay cylinder blocks",
  "walls","Thick walls made of clay stone stacks",
});

dest_dir = ({
  "/players/jaraxle/3rd/warrior/rooms/pyr_path4.c","out",
  "/players/jaraxle/3rd/pyramid/rooms/roome.c","east",
  "/players/jaraxle/3rd/pyramid/rooms/roomw.c","west",
  "/players/jaraxle/3rd/pyramid/rooms/roome2.c","northeast",
  "/players/jaraxle/3rd/pyramid/rooms/roomw2.c","northwest",
  "/players/jaraxle/3rd/pyramid/rooms/room2.c","north",
});

MOCO("/players/jaraxle/3rd/pyramid/items/statue.c"),TO);
MOCO("/players/jaraxle/3rd/pyramid/items/statue.c"),TO);
}
short(){ return ""+BOLD+""+BLK+"Dark Pyramid"+NORM+""; }
realm() { return "NT"; }

