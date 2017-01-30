#include "DEF.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIG+"Slytherin Entrance"+NORM;
long_desc =
  "  A solid stone alcove with nothing but a huge picture hanging on the rock\n"+
  "walls.  Straight overhead hangs a small chandelier with six brightly burning\n"+
  "candles.  A waist-high railing prevents anyone from falling from this high\n"+
  "precipice to the foyer below.   The stairway is the only way down.\n";

items = ({
  "picture","As you look at this picture it becomes very clear that the setting\n"+
            "is somewhere dark and foreboding.  There is a huge, stuffed chair\n"+
            "facing away from you but toward a large, stone fireplace.  You can\n"+
            "just make out the top of someone's head sitting in the chair.  On\n"+
            "the wall in the picture hangs an award of some sort",
  "chair","The back of a very comfortable and large chair sitting in front of\n"+
          "a roaring fireplace",
  "fireplace","Square cut and lined with large stones, a roaring fire is burning\n"+
              "and is the illumination of the picture",
  "head","Sparce hair covers the top of this balding head",
  "award","The award is the House Award of Slytherin from many years ago",
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
  TP->move_player("disappears#players/eurale/Pot/slytherin2.c");
  return 1; }
return 1;
}

Search(str) {
if(!str) { write("You search aimlessly but to no avail.\n"); return 1; }
write("You search the "+str+" but find nothing special.\n");
say(capitalize(TPRN)+" searches the "+str+" but finds nothing.\n");
return 1;
}
