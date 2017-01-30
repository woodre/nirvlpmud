#include "DEF.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIB+"Hufflepuff Dormitory"+NORM;
long_desc =
  "  Large, four post beds fit snugly up against the outside walls of this cozy\n"+
  "room.  At the foot of each bed is a large trunk that belongs to the bed owner.\n"+
  "A large fireplace is built into the wall between the beds and has two small\n"+
  "windows on either side of it.\n";

items = ({
  "beds","Beds with varying colored sheets and pillows",
  "pillows","Small, medium and large pillows at the head of each bed",
  "trunks","Large, retangular trunks with lots of room for 'stuff'",
  "fireplace","Blackened from use with a slightly curved top, this stone fire-\n"+
              "place provides heat on those cold winter nights",
  "windows","One solid with four panes and the other that opens to allow the\n"+
            "student's owls back in",
});

dest_dir = ({
  "players/eurale/Pot/hufflepuff2.c","left",
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
