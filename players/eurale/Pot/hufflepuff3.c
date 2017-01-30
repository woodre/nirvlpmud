#include "DEF.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIB+"Hufflepuff Dormitory"+NORM;
long_desc =
  "  Comfortable looking beds are arranged in a square pattern around the room.\n"+
  "They are supported on thick wooden frames that are high enough to allow big\n"+
  "trunks to be stored underneath.  In the center of the room is a stone pit of\n"+
  "sorts where fires have burnt recently.  A large window takes up most of the\n"+
  "outside wall.\n";

items = ({
  "beds","Thick mattresses with cozy, down comforters provide the sleeping\n"+
         "arrangements of this quiet room",
  "frames","Planks of Oak and Ash that support the thick mattresses",
  "trunks","Large, retangular trunks that students carry their belongings back\n"+
           "and forth to school in",
  "mattresses","Down filled and very thick",
  "pit","This square pit is about a foot deep and provides a place for a fire to\n"+
        "burn to heat the sleeping quarters on cold nights",
});

dest_dir = ({
  "players/eurale/Pot/hufflepuff2.c","right",
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
