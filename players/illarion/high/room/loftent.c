inherit "room/room";
#include "/players/illarion/dfns.h"

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc="The entrance to a loft apartment";
  long_desc=
"You stand at one end of an amazing well-appointed loft apartment.  Directly\n"+
"to the north is a freight elevator and a doorway, through which you can see\n"+
"a descending staircase.  To the south, the hardwood floor gives way to\n"+
"carpet, and antique furniture, and to the west, tile and cabinets.  A lamp\n"+
"above the elevator lights this small entrance area.\n";
  items= ({
    "apartment","It's very nice, take a look around",
    "elevator","A freight elevator with a locked metal gate.  It must be\n"+
               "out of order",
    "door","A very solid looking door that leads to a flight of stairs",
    "stairs","Wooden stairs, leading down",
    "floor","Polished and waxed hardwood",
    "carpet","Definately of quality, and probably old",
    "tile","A light, understated pattern, sparkling clean",
    "furtniture","Extremely valuable, both for rarity and design",
    "cabinets","Well-propotioned and clean, set on either side of the tile",
    "lamp","A nice glass lamp, clean and bright",
    "entrance","Right, that's where you are",
  });
  dest_dir= ({
    HROOM+"kitchen","west",
    HROOM+"living","south",
    HROOM+"dojomain","down",
  });
}
