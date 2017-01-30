#include "ansi.h"

inherit "room/room";

string *exits;
      
reset(arg) {
  if(arg) return;

  set_light(1);

  long_desc=
"   A long, well paved road leads to a small town.  Along side the\n"+
"road are large fields filled with either cows or sheep.  The fields\n" + 
"seem to roam forever in the distance.  To the west, a small dirt\n"+
"road that leads out past the pastures.  The small town can be seen\n"+
"in the near distance.\n";

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
       "dirt road",
          "The road is covered in dirt and gravel",
	"west",
	   "A small dirt road is toward the west",
	"dirt",
	   "A small dirt road that can barely fit one vechile on it",
   });

   dest_dir=({
	"/players/katya/area/bolivar/town/r/road4","north",
 	"/players/katya/area/bolivar/town/r/road2","south",
   });
}

   short() {

      return "A road";

}
