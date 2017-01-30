#include "ansi.h"

inherit "room/room";

string *exits;
      
reset(arg) {
  if(arg) return;

  set_light(1);

  long_desc=
"   The road surrounds the town square.  In the middle of the square,\n"+
"is a large 4 story court house.  The court house has built in the\n"+
"late 1800's.   A home medical supplies shop sits beside a small road\n"+
"that seems to be currently under construction.  Across the road is a\n"+
"hardware store.\n";
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
	"small road", 
	   "The small road seems to be under construction, but soon might lead somewhere",
	"store",
	   "An old hardware store, the front of the building is made up of all\n"+
	   "windows.  It looks like it has been here for as long as the town",
	"shop",
	   "A medical supply shop that sells walkers, crutches and other needed supplies",
   });

   dest_dir=({
	"/players/katya/area/bolivar/town/r/road12","east",
 	"/players/katya/area/bolivar/town/r/road10","southeast",
   });
}

   short() {

      return "Bolivar";

 }
