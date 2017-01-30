#include "ansi.h"

inherit "room/room";

string *exits;
      
reset(arg) {
  if(arg) return;

  set_light(1);

  long_desc=
"   The road surrounds the town square.  In the middle of the square,\n"+
"is a large 4 story court house.  The court house has built in the\n"+
"late 1800's.  A rent to own shop is at the corner of the square .\n";
   items=({
	"court house",
	   "The court house is a 4 story community builting, which\n"+
	   "was built off center, due to the pony express route\n"+
	   "a statue of Simon Bolivar stands up on the very top of\n"+
	   "the building holding his sword out protecting the town\n"+
 	   "from any hardships.  The building was made out of large\n"+
	   "grey colored stones", 
	"shop",
	   "A rent to own shop, that seems to have everything from furniture to washer and dryers",
	"road",
	   "The road surrounds the court house, it is made of off white cement",
	"cement",
	   "The cement is nicely placed onto the ground, surrounding the court house", 
   });

   dest_dir=({
	"/players/katya/area/bolivar/town/r/road9","southwest",
 	"/players/katya/area/bolivar/town/r/road7","northeast",
   });
}

   short() {

      return "Bolivar";

 }
