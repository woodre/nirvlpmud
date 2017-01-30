#include "ansi.h"

inherit "room/room";

string *exits;
      
reset(arg) {
  if(arg) return;

  set_light(1);

  long_desc=
"   The road surrounds the town square.  In the middle of the square,\n"+
"is a large 4 story court house.  The court house has built in the\n"+
"late 1800's.  All around the court house are small shops that are\n"+
"owned by families who grew up in this small personal town.\n";
   items=({
	"court house",
	   "The court house is a 4 story community builting, which\n"+
	   "was built off center, due to the pony express route\n"+
	   "a statue of Simon Bolivar stands up on the very top of\n"+
	   "the building holding his sword out protecting the town\n"+
 	   "from any hardships.  The building was made out of large\n"+
	   "grey colored stones", 
	"town square",
	   "The town square sits off angel and is surrounded by many shops", 
	"road",
	   "The road surrounds the court house, it is made of off white cement",
	"shops",
	   "The small family shops circle the square",
	"cement",
	   "The cement is nicely placed onto the ground, surrounding the court house", 
   });

   dest_dir=({
	"/players/katya/area/bolivar/town/r/road8","southwest",
 	"/players/katya/area/bolivar/town/r/road6","south",
	"/players/katya/area/bolivar/town/r/road16","northeast",
   });
}

   short() {

      return "Bolivar";

 }
