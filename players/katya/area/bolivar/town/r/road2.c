#include "ansi.h"

inherit "room/room";

string *exits;
      
reset(arg) {
  if(arg) return;

  set_light(1);

  long_desc=
"   A long, well paved road leads to a small town.  Along side the\n"+
"road are large fields filled with either cows or sheep.  The fields\n" + 
"seem to roam forever in the distance.  Small houses can be seen in\n"+
"in the distance, beyond the fields of grass.  The small town can be\n"+
"seen in the horizon.\n";

   items=({
	"fields",
	   "The fields are covered in bright green grass as far as the eye can see",
	"road",
	   "The road is well paved with white cement",
	"town",
	   "A small town can be seen in the distance",
	"cows",
	   "Black and white cows graze in the fields",
	"sheep",
	   "Dirty white fluffy sheep roam the distance fields",
	"cement",
	   "The cement seems rough and covered in dust",
	"grass",
	   "The bright green grass flows in the soft wind",
	"horizon",
	   "Peeking over the horizon you see a small town appearing",
	"houses",
	   "Large white farm houses are across the fields",
   });

   dest_dir=({
	"/players/katya/area/bolivar/town/r/road3","north",
 	"/players/katya/area/bolivar/town/r/road1","south",
   });
}

   short() {

      return "A road";

}
