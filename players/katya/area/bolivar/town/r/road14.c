#include <ansi.h>

inherit "room/room";

string *exits;
      
reset(arg) {

if(!present("seth")) {
move_object(clone_object("/players/katya/area/bolivar/town/m/seth.c"),this_object());
}

if(!present("kristin")) {
move_object(clone_object("/players/katya/area/bolivar/town/m/kristin.c"),this_object());
}

  if(arg) return;

  set_light(1);

  long_desc=
"   The road surrounds the town square.  In the middle of the square,\n"+
"is a large 4 story court house.  The court house has built in the\n"+
"late 1800's.  A title loan shop is at the corner.\n";
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
	"shop",
	   "A small shop that gives loans, if you have the title to your car",
   });

   dest_dir=({
	"/players/katya/area/bolivar/town/r/road15","southeast",
 	"/players/katya/area/bolivar/town/r/road13","north",
   });
}

   short() {

      return "Bolivar";

 }
