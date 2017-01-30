#include "ansi.h"

inherit "room/room";

string *exits;
      
reset(arg) {
  if(arg) return;

  set_light(1);

  long_desc=
"   The road surrounds the town square.  In the middle of the square,\n"+
"is a large 4 story court house.  The court house has built in the\n"+
"late 1800's.  A small road turns to the west leading no where.  Across\n"+
"the small road is a two story building, on the bottom floor seems to be \n"+
"a lawyers office and the top floor is a dance studio.\n";
   items=({
	"court house",
	   "The court house is a 4 story community builting, which\n"+
	   "was built off center, due to the pony express route\n"+
	   "a statue of Simon Bolivar stands up on the very top of\n"+
	   "the building holding his sword out protecting the town\n"+
 	   "from any hardships.  The building was made out of large\n"+
	   "grey colored stones", 
	"office",
	   "A small town law office of, Douglas, Lynch and Haun",
	"road",
	   "The road surrounds the court house, it is made of off white cement",
	"cement",
	   "The cement is nicely placed onto the ground, surrounding the court house", 
	"studio", 
	   "The dance studio is on the second floor of this old white building\n",
	"building",
	   "A two story, white building with chipping paint\n",
	"small road",
	   "The small road seems to just go to a dead end\n",
   });

   dest_dir=({
	"/players/katya/area/bolivar/town/r/road10","northwest",
 	"/players/katya/area/bolivar/town/r/road8","northeast",
   });
}

   short() {

      return "Bolivar";

 }
