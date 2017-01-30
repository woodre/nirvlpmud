#include "DEF.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIB+"Hufflepuff Entrance"+NORM;
long_desc =
  "  A solid stone alcove with nothing but a huge picture hanging on the rock\n"+
  "walls.  Straight overhead hangs a small chandelier with six brightly burning\n"+
  "candles.  A waist-high railing prevents anyone from falling from this high\n"+
  "precipice to the foyer below.   The stairway is the only way down.\n";

items = ({
  "picture","A very rotund lady dressed in red velvet.  In her hand she holds\n"+
            "a small scepter and there is a crown of some sort on her round\n"+
            "head.  She is smiling and sitting in a sturdy, throne-like chair",
  "scepter","Upon closer inspection, it appears to be a delicate wand",
  "crown","Her ruby headband is inscribed with the word 'Hufflepuff Queen'",
  "chair","An ornately carved wooden chair with the Hogwart insignia on it",
  "shadow","This shadow seems to indicate that the picture is slightly away from\n"+
           "the wall like it has been moved recently",
  "farmer","This fellow looks a bit odd, like he might be wearing armor under his\n"+
           "bib overalls",
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
  TP->move_player("disappears#players/eurale/Pot/hufflepuff2.c");
  return 1; }
return 1;
}

Search(str) {
if(!str) { write("You search aimlessly but to no avail.\n"); return 1; }
write("You search the "+str+" but find nothing special.\n");
say(capitalize(TPRN)+" searches the "+str+" but finds nothing.\n");
return 1;
}
