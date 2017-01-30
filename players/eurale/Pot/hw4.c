#include "DEF.h"
inherit "room/room";

int F;
reset(arg) {
  if(arg) return;
set_light(1);
F = 1;

short_desc = "Hogwarts";
long_desc =
  "  These solid stone stairs move about as if they had a mind of their own.  The\n"+
  "top step ends at different openings as the stairs move.  Flickering candles light\n"+
  "the eerie way and the air seems a bit cool and damp here.  The foyer below is\n"+
  "hardly visible because of the massive candle chandelier hanging beside the\n"+
  "stairway.  A large suit of armor sits just off to the side of the stairs.\n";

items = ({
  "stairs","Moving solid, stone steps that curve both up and down",
  "armor","A full set of knights armor complete with with a shielded helmet.  A\n"+
          "large purple feather adorns the helmet and the whole suit is polished\n"+
          "to a gleaming sheen",
  "feather","This feather was plucked from some unknown source and is a beautiful\n"+
            "addition to the fine helmet",
  "openings","Small doorways with stone porches leading to different places",
  "candles","Large, colorful wax candles that never seem to burn down",
  "foyer","Blocked by the large, hanging chandelier that lights the downstairs",
  "chandelier","Huge, twelve feet across at least and with hundreds of burning\n"+
               "wax candles that give off plenty of light",
});

dest_dir = ({
  "players/eurale/Pot/hw3.c","down",
  "players/eurale/Pot/gryffindor.c","up",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("Search","search");
  add_action("Pluck","pluck");
}

Pluck(str) {
if(!str) { write("Pluck what?\n"); return 1; }
if(str == "feather") {
  if(F == 0) {
    write("You try to pluck the purple feather but it growls and resists.\n");
    return 1; }
  write("You pluck the beautiful purple feather.\n");
  F = 0;
  return 1; }
}

Search(str) {
if(!str) { write("You search aimlessly but to no avail.\n"); return 1; }
write("You search the "+str+" but find nothing special.\n");
say(capitalize(TPRN)+" searches the "+str+" but finds nothing.\n");
return 1;
}
