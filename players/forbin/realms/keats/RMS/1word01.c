#include "/players/forbin/realms/keats/keatsdefine.h"
inherit "/players/forbin/realms/keats/room.c";

string Location;

reset(arg) 
{
  if(arg) return;
  short_desc = KEATS;
  Location = "The Avenue of the Word";
  long_desc = 
    "\n                "+HIW+"The Avenue of the Word"+C+"  (["+NORM+"north,south"+C+"])"+NORM+"\n"+
    "The main artery of the city runs fairly straight here, dropping off\n"+
    "in a rather steep decline to the south, while continuing north to\n"+
    "an open space within the city.  The avenue is split in two by a\n"+
    "wide median of grass and trees and is bordered on each side by\n"+
    "cobbled sidewalks crowded with passersby.  Both sides of the\n"+
    "thoroughfare are lined with buildings, and people hurriedly go in\n"+
    "and out of them.\n";
  add_item(({"artery","avenue","avenue of word","avenue of the word","thoroughfare"}),
    "The avenue here runs down a drop off to the south, while to the north it leads\n"+
    "to a large open space in the distance");
  add_item("decline",
    "The slope to the south is fairly steep, and the avenue makes several switchbacks\n"+
    "to make travel down it less severe");
  add_item(({"median","grass","tree","trees"}),
    "The median that splits The Avenue of the Word is beautifully landscaped with\n"+
    "lush, green grass and several types of small, deciduous tree species");
  add_item(({"space","open space"}),
    "Up to the north, you can make out a large open gap in the city's buildings.  It\n"+
    "appears to be some sort of town square or large meeting space");
  add_item(({"sidewalk","sidewalks","cobbled sidewalk","cobbled sidewalks"}),
    "The wide sidewalks that border The Avenue of the Word are made of dark, red\n"+
    "stones and have been worn smooth with centuries of use");
  add_item(({"building","buildings"}),
    "Buildings and shops dot the storefronts along each side of the avenue.  None\n"+
    "of them interest you at the moment");
  add_item(({"people","passerby","passersby"}),
    "The City of Keats is alive with movement; some rush here and there, entering\n"+
    "and exiting shops, while others stroll along the avenue");
  add_exit(RMS+"1square.c", "north");
  add_exit(RMS+"1word02.c", "south");
  set_light(1);
}
