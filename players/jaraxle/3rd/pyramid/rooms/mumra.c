#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(-1);

long_desc =
  "   "+BLK+BOLD+"An enormous throne room.  Four large stone statues of evil spirits\n"+
  "stand around the throne, forming a square. Two gargoyles sit defiantly\n"+
  "above the throne on two columns.  A large throne made of stone sits in\n"+
  "the middle of the room.  An iron cauldron is bubbling over slowly, on\n"+
  "each side of the throne."+NORM+"\n";
items = ({
  "statues","Four huge statues of the Ancient Spirits of Evil",
  "throne","A large, stone chair",
  "gargoyles","Two gargoyles that sit on top of columns.\nEach gargoyle looks very lifelike",
  "columns","Large round columns with a gargoyle perched on the top",
  "cauldron","A large iron bowl swirling with "+MAG+"magenta"+NORM+" and "+BLU+"blue"+NORM+" swirls",
});

MOCO("/players/jaraxle/3rd/pyramid/mon/mumra.c"),TO);
dest_dir = ({
  "/players/jaraxle/3rd/pyramid/rooms/archway3.c","exit",
});
}
short(){ return ""+BOLD+""+BLK+"Dark Pyramid"+NORM+""; }
realm() { return "NT"; }

