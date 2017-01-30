/* Hall 2 (top of stairs), Created <6/19/01> by Jara */

#include "/players/jara/misc/ansi.h"
#include "defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Zercher Castle- Landing";
  long_desc=
    "  The uppermost landing has a magnificent window overlooking the city\n"+
    "and land that stretches beyond. The curtains are made of a thick, red\n"+
    "satin, and the rod above the window is a delicately braided metal. The\n"+
    "spiral staircase leads down to the second level of the castle and the\n"+
    "hallway leads to the east and west.\n";
  items=({
    "window",
    "A wide window curtained with thick satin. The view is splendid",
    "view",
    "The city, with high stone walls and modern buildings is just across a\n"+
    "large clearing. The beach and sea is just beyond, and in the far distance,\n"+
     "an isle is barely visible",
    "walls",
    "The stone walls of the city are thick with mortar and strong stones",
    "buildings",
    "The city has buildings roofed in a new and modern way", 
    "clearing",
    "The field is to the southeast of the castle",
    "beach",
    "A sandy beach, bordered by high cliffs and rocky shoreline",
    "sea",
    "A dark sea, colored grey by the fogs and clouds that keep the sunlight\n"+
    "from penetrating",
    "isle",
    "An isle thick with jungle",
    "curtains",
    "The satin curtains are rich in color, and drape over the window",
    "rod",
    "A rod made of unknown metal has been braided and made into an elegant\n"+
    "curtain rod",
    "staircase",
    "The spiral staircase is sturdy and made of stone",
    "hallway",
    "The hallway on this floor is lit by candlelight. The darkness seems\n"+
    "to cling to the walls" });
  dest_dir=({
    PATH+"hall6","down",
    PATH+"hall1","east",
    PATH+"hall3","west" });
}
