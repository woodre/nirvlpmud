#include "ansi.h"

inherit "room/room";

string *exits;
      
reset(arg) {

if(!present("lisa")) {
move_object(clone_object("/players/katya/area/bolivar/town/m/lisa.c"),this_object());
}

if(!present("julie")) {
move_object(clone_object("/players/katya/area/bolivar/town/m/julie.c"),this_object());
}

if(!present("ann")) {
move_object(clone_object("/players/katya/area/bolivar/town/m/ann.c"),this_object());
} 

  if(arg) return;

  set_light(1);

  long_desc=
"   A nice looking buffet has been set up along the west wall.  On the east\n"+
"wall are a few booths and tables for customers to eat at.  To the south of\n"+
"the restaurant is a play area for the children to play in after tehy are \n"+
"finished eating.  The register and kitchen are in the northeastern part of\n"+
"the restaurant.\n";

   items=({
	"buffet",
	   "A large buffet filled with many different types of pizza",
	"wall",
           "The walls are just a plain white with a bit of grey splattered on them",
	"boothes",
	   "The grey boothes are big enough to sit four people at them",
	"tables",
	   "The grey tables and chairs are a good place to sit if you have six or more people",
	"restaurant",
	   "Breadeaux Pizza seems to be a good place to eat lunch",
	"register",
	   "The register is looks like it is very new and computerized",
	"area",
	   "The play area is large and has a lot of tubes children can run in and out of\n"+
	   "and have lots of fun.  Also, an area with plastic balls the children can use",
	"kitchen",
	   "From the view, the kitchen seems to be very large and clean",

   });

   dest_dir=({
	"/players/katya/area/bolivar/town/r/road13","out",

   });
}

   short() {

      return "Breadeaux Pizza";

 }
