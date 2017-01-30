#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "The "+BOLD+""+BLK+"Ruins"+NORM+"";
long_desc =
"   This room is crafted into a perfect circle. Several holy symbols\n"+
"cover the marble floor, each engraved in gold.  Wall sconces provide\n"+
"light to this warm room. An archway to the south leads to a small\n"+
"chamber. To the east is a hallway and to the north is the wall room.\n";

items = ({
  "symbols",
  "Each symbol is carved deeply into the floor, their etched\n"+
  "surface filled with some type of shining blue metal. Even\n"+
  "with all the evil that surrounds the ruins for some reason\n"+
  "the symbols traced here on the floor are more at home than\n"+
  "anything that lies outside in the cursed ruins. You feel that\n"+
  "this is a place of reverance and a deep feeling of goodness\n"+
  "flows through it",
  "sconces",
  "Trimmed in gold, they blaze with a warm endless light",
  "floor",
  "Made from polished marble, you can actually see your\n"+
  "reflection in its stones",
});

dest_dir = ({
  "/players/maledicta/ruins/rooms/r17.c","north",
  "/players/maledicta/ruins/rooms/r20.c","south",
  "/players/maledicta/ruins/rooms/r19.c","east",
});

}
