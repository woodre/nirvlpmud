#include "DEF.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Great Hall";
long_desc =
  "  This spacious room seems to go on forever in all directions.  Overhead the\n"+
  "ceiling gives the impression of openness skyward.  Four long tables run the\n"+
  "length of the hall with a shorter table across the front from side to side.\n"+
  "Candles of all sizes float a few feet above the tables and give light to the\n"+
  "entire hall.\n";

items = ({
  "ceiling","The ceiling changes to match the outside conditions making it look\n"+
            "and feel as if the room was open to the sky",
  "tables","The long tables each seat one of the Hogwart houses and the front\n"+
           "table accomodates the staff.  All the tables are beautifully set with\n"+
           "dinnerware and are polished to a satin sheen",
  "candles","Hundreds and hundreds of candles of all shapes and sizes mysteriously\n"+
            "floating above the tables to provide light",
});

dest_dir = ({
  "players/eurale/Pot/hw3.c","south",
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
