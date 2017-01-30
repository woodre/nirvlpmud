#include "DEF.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Hagrid's Cabin";
long_desc =
  "  To the east is a large window looking out on the school of Hogwarts.  There\n"+
  "is also a heavy wooden door with a small rug in front of it.  A large table\n"+
  "and two chairs line the northern wall.  To the west is a large bed with wooden\n"+
  "posts at each corner.  An open, stone fireplace takes up most of the southern\n"+
  "wall.  Hams and pheasants hang from the ceiling.\n";

items = ({
  "hams","Various sized ham shanks with protruding bones",
  "pheasants","Pheasants of different sizes, some plucked but all drying",
  "rug","A small, oval rug, woven from the fur of some kind of beast",
  "table","Thick, wooden legs support this large, square, wooden tabletop",
  "chairs","Made from logs, probably cut from the nearby forest.  They would\n"+
           "most certainly support massive weight",
  "bed","Oversized and unkempt, this huge bed would accomodate at least two\n"+
        "normal sized individuals and is coverd by a patchwork quilt",
  "posts","Twelve inches in diameter, these posts support the weight of this\n"+
          "massive bed",
  "fireplace","Just as the walls are made of stone, so too is this large open\n"+
              "fireplace.  There is a metal rod spanning the opening from which\n"+
              "to hang cooking pots or meat to roast and ashes from burning wood\n"+
              "litter the bottom of the opening",
  "rod","A heavy, metal rod cemented into both sides of the fireplace when it\n"+
        "was constructed",
  "ashes","Wood ashes from the logs of cooking and heating",
  "window","Outside, in the distance, you can see part of the Hogwart's School of\n"+
           "of magic.  This four-paned window provides plenty of light for the\n"+
           "single room of this hut",
  "hogwarts","Not much of the building can be seen from this distance",
  "door","A heavy wooden door with metal hinges.  At the bottom appear to be some\n"+
         "sort of scratches",
  "scratches","They appear to have been made by some kind of clawed creature who\n"+
              "was probably trying to get out",
});

dest_dir = ({
  "players/eurale/Pot/hw6.c","out",
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
