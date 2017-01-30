#include <ansi.h>

inherit "room/room";

string *exits;
      
reset(arg) {

if(!present("lillith")) {
move_object(clone_object("/players/katya/area/bolivar/town/m/lillith.c"),this_object());
}

if(!present("justin")) {
move_object(clone_object("/players/katya/area/bolivar/town/m/justin.c"),this_object());
}

if(!present("samantha")) {
move_object(clone_object("/players/katya/area/bolivar/town/m/samantha.c"),this_object());
}

  if(arg) return;

  set_light(1);

  long_desc=
"   The road surrounds the town square.  In the middle of the square,\n"+
"is a large 4 story court house.  The court house has built in the\n"+
"late 1800's.   A small craft store sits between the lawyer's office\n"+
"and a home medical supplies shop.\n";
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
	"craft store", 
	   "A small craft store that sells hand made items\n",
	"store",
	   "A small craft store that sells hand made items\n",
	"shop",
	   "A medical supply shop that sells walkers, crutches and other needed supplies\n",
   });

   dest_dir=({
	"/players/katya/area/bolivar/town/r/road11","northwest",
 	"/players/katya/area/bolivar/town/r/road9","southeast",
   });
}

   short() {

      return "Bolivar";

 }
