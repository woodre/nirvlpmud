#include "DEF.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIR+"Gryffindor Entrance"+NORM;
long_desc =
  "  A solid stone alcove with nothing but a huge picture hanging on the rock\n"+
  "walls.  Straight overhead hangs a small chandelier with six brightly burning\n"+
  "candles.  A waist-high railing prevents anyone from falling from this high\n"+
  "precipice to the foyer below.   The stairway is the only way down.\n";

items = ({
  "picture","A country scene with a farmer in the foreground.  He seems to be\n"+
            "holding a hoe and is wearing a straw hat.  There is a dark shadow\n"+
            "around the picture",
  "shadow","This shadow seems to indicate that the picture is slightly away from\n"+
           "the wall like it has been moved recently",
  "farmer","This fellow looks a bit odd, like he might be wearing armor under his\n"+
           "bib overalls",
  "hoe","An ordinary garden tool with a flat blade on a wooden handle",
  "hat","A round, wide-brimed straw hat",
  "walls","Solid stone with small bits of mortar between the rocks holding them\n"+
          "in place",
  "rocks","Dense, dark stone of immense thickness",
  "chandelier","A small, metal chandelier hanging by a chain with six flickering\n"+
               "candles to provide light",
  "candles","Large, round, wax candles with long wicks",
  "railing","Metal railings with ornate metal posts between top and floor",
  "foyer","Most hidden by the huge chandelier that hangs in the main foyer",
  "stairway","Stone steps that seem to move from place to place",
});

dest_dir = ({
  "players/eurale/Pot/hw4.c","down",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("Search","search");
  add_action("Move","move");
}

Move(str) {
if(!str || str != "picture") { write("Move what?\n"); return 1; }
if(str == "picture") {
  write("As you move the picture, you are pulled through the hole behind it\n"+
        "by some invisible force......\n\n");
  TP->move_player("disappears#players/eurale/Pot/gryffindor2.c");
  return 1; }
return 1;
}

Search(str) {
if(!str) { write("You search aimlessly but to no avail.\n"); return 1; }
write("You search the "+str+" but find nothing special.\n");
say(capitalize(TPRN)+" searches the "+str+" but finds nothing.\n");
return 1;
}
