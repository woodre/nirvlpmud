#include "ansi.h"

#define TP this_player()

inherit "room/room";

reset(arg) {

if(!present("kimberly")) {
move_object(clone_object("/players/katya/area/bolivar/town/m/kimberly.c"),this_object());
}

if(!present("cathy")) {
move_object(clone_object("/players/katya/area/bolivar/town/m/cathy.c"),this_object());
}

  if(arg) return;

  set_light(1);

  long_desc=
"   The road surrounds the town square.  In the middle of the square,\n"+
"is a large 4 story court house.  The court house has built in the\n"+
"late 1800's.   A small clothing store that has a large frog painted\n"+
"on the front window of the store.\n";
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
          "A small clothing store called 'Frog's & Friends'.  Might try and 'enter' it?",
	"frog",
	   "A large green frog that has been painted on the window of the store",
   });

   dest_dir=({
	"/players/katya/area/bolivar/town/r/road7","southwest",
 	"/players/katya/area/bolivar/town/r/road15","northwest",
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
      this_player()->move_player("enter#players/katya/area/bolivar/town/r/frogs.c");
      say(this_player()->query_name()+" enters Frogs & Friends.\n");
      return 1;}
}
