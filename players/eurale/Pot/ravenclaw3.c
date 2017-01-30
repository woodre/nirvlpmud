#include "DEF.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIY+"Ravenclaw Dormitory"+NORM;
long_desc =
  "  Old beds with tall posts at each corner fill most of the room.  Large trunks\n"+
  "sit at the foot of each bed.  A large, oval rug covers the floor.  One large,\n"+
  "window takes up nearly the entire north wall.\n";

items = ({
  "beds","Four poster beds with curtains to provide privacy while sleeping or "+
         "studying",
  "posts","Square wooden posts about 7 feet tall",
  "trunks","Large trunks with locks to store personal items",
  "locks","Magical locks with no key holes",
  "rug","A thick weave rug with the Ravenclaw crest on it",
  "window","A double swing out window to allow air and owls access to the room",
});

dest_dir = ({
  "players/eurale/Pot/ravenclaw2.c","east",
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
