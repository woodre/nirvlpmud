#include <ansi.h>

#define TP this_player()

inherit "room/room";

reset(arg) {
  if(arg) return;

  set_light(1);

  long_desc=
"   The road surrounds the town square.  In the middle of the square,\n"+
"is a large 4 story court house.  The court house has built in the\n"+
"late 1800's.  Breadeaux Pizza is sits here beside the custard shop.\n"+
"Inside they have a play area for children.\n";
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
	"breadeaux",
           "Breadaux Pizza has large windows in the front, looking inside there is\n"+
           "a large area for children to play, after they are finished eating.\n"+
           "Might want to try and 'enter' it",
	"shop",
	   "A small custard shop sits in a pink building with a picture of a ice cream cone",
   });

   dest_dir=({
	"/players/katya/area/bolivar/town/r/road14","south",
 	"/players/katya/area/bolivar/town/r/road12","northwest",
   });
}

   short() {

      return "Bolivar";

 }
init(){
   ::init();
   { add_action("breadeaux", "enter");}
}

breadeaux(str){
   if(!str){ notify_fail("What are you trying to enter?\n"); return 0; }
   if(str == "breadeaux") {
      this_player()->move_player("enter#players/katya/area/bolivar/town/r/pizza.c");
      say(this_player()->query_name()+" enters Breadeaux Pizza.\n");
      return 1;}
}
