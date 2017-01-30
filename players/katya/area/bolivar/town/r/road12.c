#include "ansi.h"

#define TP this_player()

inherit "room/room";
      
reset(arg) {
  if(arg) return;

  set_light(1);

  long_desc=
"   The road surrounds the town square.  In the middle of the square,\n"+
"is a large 4 story court house.  The court house has built in the\n"+
"late 1800's.  A small custard shop sits at the corner, across from\n"+
"old time hardware store.\n";
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
 	   "Western Auto is an old store, the front of the building is made up\n"+
           "of windows.  It looks has if it has been here as long as the town\n"+
           "Might want to try and 'enter' the store",
	"shop",
	   "A small custard shop sits in a pink building with a picture of a ice cream cone",
   });

   dest_dir=({
	"/players/katya/area/bolivar/town/r/road11","west",
 	"/players/katya/area/bolivar/town/r/road13","southeast",
   });
}

   short() {

      return "Bolivar";

 }

init(){
   ::init();
   { add_action("store", "enter");}
}

store(str){
   if(!str){ notify_fail("What are you trying to enter?\n"); return 0; }
   if(str == "store") {
      this_player()->move_player("enter#players/katya/area/bolivar/town/r/auto.c");
      say(this_player()->query_name()+" enters Western Auto.\n");
      return 1;}
}
