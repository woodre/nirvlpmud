#include "ansi.h"

inherit "room/room";

string *exits;
      
reset(arg) {
  if(arg) return;

  set_light(1);

  long_desc=
"   The road surrounds the town square.  In the middle of the square,\n"+
"is a large 4 story court house.  The court house has built in the\n"+
"late 1800's.   A very nice fancy jewelry store.  It seems to have\n"+
"all types of expensive jewelry, from huge diamond rings to rolexes.\n";
   items=({
	"court house",
	   "The court house is a 4 story community builting, which\n"+
	   "was built off center, due to the pony express route\n"+
	   "a statue of Simon Bolivar stands up on the very top of\n"+
	   "the building holding his sword out protecting the town\n"+
 	   "from any hardships.  The building was made out of large\n"+
	   "grey colored stones", 
	"road",
	   "The road surrounds the court house, it is made of off white cement",
	"cement",
	   "The cement is nicely placed onto the ground, surrounding the court house", 
	"store",
	   "Through the windows of the jewerly store you can see all types of\n"+
	   "diamond jewerly and all other types of expensive items",
   });

   dest_dir=({
	"/players/katya/area/bolivar/town/r/road16","southeast",
 	"/players/katya/area/bolivar/town/r/road14","northwest",
   });
}

   short() {

      return "Bolivar";

 }
