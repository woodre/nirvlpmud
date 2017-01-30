#include "ansi.h"

inherit "room/room";

string *exits;

reset(arg) {
  if(arg) return;

   set_light(1);

   long_desc=
"   A long, well paved road leads to a small town.  Along side the\n"+
"road are large fields filled with either cows or sheep.  The fields\n" + 
"seem to roam forever in the distance.  The small town can be seen\n"+
"in the dim horizon.\n";

   items=({
       "fields",
   "The fields are covered in bright green grass as far as the eye can see",
       "road",
	   "The road is well paved with white cement",
	"town",
	   "A small town can barely be seen in the distance",
	"cows",
	   "Black and white cows graze in the fields",
        "sheep",
	   "Dirty white fluffy sheep roam the distance fields",
	"cement",
	   "The cement seems rough and covered in dust",
	"grass",
	   "The bright green grass flows in the soft wind",
       "town",
           "The town is too far for you to see",
	"horizon",
	   "Peeking over the horizon is a small hidden town",
   });

   dest_dir=({
        "/players/katya/area/bolivar/town/r/road2","north",
        "/room/south/sforst6","out",
   });
}

   short() {

      return "A road";

}
