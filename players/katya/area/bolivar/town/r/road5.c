#include "ansi.h"

inherit "room/room";

string *exits;
      
reset(arg) {
  if(arg) return;

  set_light(1);

  long_desc=
"   You have reached the city limits of the small town.  The road\n"+
"seems to lead down to the center of the town.  A bank is on the \n"+
"east side of the road, and the west side is a large Wal-Mart.\n"+
"The further down the road are many different businesses.  A small\n"+
"sign stands right outside the town.\n";
   items=({
	"town",
	   "The town seems to be very small",
	"road",
	   "The road has been covered in tar giving it a black look",
	"bank",
	   "A huge bank made out of tinted windows and brick",
	"wal-mart",
	   "A huge white building with blue highlights",
	"businesses",
	   "The businesses are coming into sight, but are still hard to make out",
	"sign",
	   "The sign reads:\n\n"+
			"Welcome to Bolivar!\n"+               
                         "Population: 9,143",
   });

   dest_dir=({
	"/players/katya/area/bolivar/town/r/road6","north",
 	"/players/katya/area/bolivar/town/r/road4","south",
   });
}

   short() {

      return "Bolivar";

 }
