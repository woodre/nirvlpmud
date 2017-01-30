#include "DEF.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIG+"Slytherin Commons"+NORM;
long_desc =
  "  A large fireplace fills the western wall.  Small sofas dot the room and\n"+
  "provide seating for the Slytherin members.  Small circular tables sit around\n"+
  "the outside of the room and provide studying space.  A large banner hangs from\n"+
  "the ceiling of the room.  Two narrow staircases are visible to the north and\n"+
  "south.\n";

items = ({
  "fireplace","A large, open fireplace with a bright "+HIG+"green flame"+NORM+
              " burning",
  "sofas","Worn but comfortable sofas just large enough for two people to sit",
  "tables","Wooden tables with many scars from past students",
  "banner","A large green and black banner with the Slytherin House symbol",
  "ceiling","The ceiling is dark and smooth, almost like the darkness of night",
  "staircases","Exits to the Slytherin dormitories",
});

dest_dir = ({
  "players/eurale/Pot/slytherin4.c","north",
  "players/eurale/Pot/slytherin3.c","south",
  "players/eurale/Pot/slytherin","out",
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
