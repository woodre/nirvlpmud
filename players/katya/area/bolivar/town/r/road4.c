#include "ansi.h"

inherit "room/room";

string *exits;
      
reset(arg) {
  if(arg) return;

  set_light(1);

  long_desc=
"   The road seems to be coming closer to the town.  Businesses are\n"+
"becoming visible, as the pastures are coming to an end.  The cows\n"+
"and sheep seem to be scarce as houses seem to be scattered about\n"+
"on both sides of the road.  Toward the north is the small town.\n";

   items=({
	"fields",
	   "The fields are covered in bright green grass",
	"road",
	   "The road is well paved with white cement",
	"town",
	   "A small town is becoming more visible",
	"cows",
	   "A few black and white cows graze in the lasting fields",
	"sheep",
	   "Dirty white fluffy sheep roam the distance fields",
	"businesses",
	   "The businesses are coming into site, but are still hard to make out",
	"north",
	   "A small town emerges from the pastures",
	"pastures",
	   "The green pastures are coming to an end",
	"houses",
	   "The houses flood the sides of the road",
   });

   dest_dir=({
	"/players/katya/area/bolivar/town/r/road5","north",
 	"/players/katya/area/bolivar/town/r/road3","south",
   });
}

   short() {

      return "A road";

 }
