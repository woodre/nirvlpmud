#include "ansi.h"

inherit "room/room";

string *exits;
      
reset(arg) {
  if(arg) return;

  set_light(1);

  long_desc=
"   A statue, of Bolivar's founder, stands to the east of the road.\n"+
"To the west of the road is where the construction of Subway is\n"+
"currently happening.  North is where the town square is.\n";
   items=({
	"statue",
	   "The statue is of General Simon Bolivar.  A little plaque sits under the statue",
	"plaque",
           "The plaque reads:\n\n"+
	   "   General Simon Bolivar was a South American war hero.\n"+
	   "   Bolivar has existed as a city since Nov 10, 1883.\n"+
           "   On Feb 15, 1881, it was organized as a fourth-class city",
	"road",
	   "The road has been covered in tar giving it a black look",
	"subway",
	   "Subway is currently under construction",
	"north",
	   "You see the town's square",

   });

   dest_dir=({
	"/players/katya/area/bolivar/town/r/road7","north",
 	"/players/katya/area/bolivar/town/r/road5","south",
   });
}

   short() {

      return "Bolivar";

 }
