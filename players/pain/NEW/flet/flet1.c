inherit "/room/room";
#include "/players/pain/color.h"

reset() {
  short_desc = "Entrance to the "+BOLD+GREEN+"Flet"+END;
  long_desc = "You have reached the entrance to the "+BOLD+GREEN+"Elven Flet"+END+".\n"+
	"The flet is a \"floating\" city of sorts, suspended high above\n"+
	"the Elven Vale amongst the trees. Wooden walkways connect the\n"+
	"the city from tree to tree. The sun shines brightly up here, the\n"+
	"canopy of leaves is beneath you, protecting the flet from detection\n"+
	"from below. You are overwhelmed by the quiet beauty of this place\n"+
	"which you are certain has stood here for thousands of years.\n";

  set_light(1);
	
  dest_dir = ({
	"/players/pain/NEW/flet/flet2", "east",
/*  Removed exit as there is no room flet20 - eurale
	"/players/pain/NEW/flet/flet20", "west",
*/
	"/players/pain/NEW/flet/grove_c", "descend",
	});

  items = ({
	"canopy", "The thick canopy of leaves lies beneath you like a green blanket",
	"walkways", "Wooden walkways extend to the east and west, connecting this\n"+
		"tree with the others around it",
	"flet", "The Flet is the suspended city of the Elves of the Hidden Vale.\n"+
		"It reaches out as far as you can see, high above the canopy of leaves\n"+
		"which provides ample protection from detection below. The leaves are\n"+
		"thinner here, allowing you a view of the sky and the walkways around\n"+
		"you. This is an ancient and holy place",
	});
	
  call_out("noises",10);
}

init() {
  ::init();
}

noises() {
int number;

   while(remove_call_out("noises") != -1);
   if ( !present(PLAYERID, this_object()) ) return;
  number = random(3);
  if(number == 0) {
	/* noise 1 */
	tell_room(this_object(),
		"You hear the sweet songs of the birds beneath you.\n");
  }
  if(number == 1) {
	/* noise 2 */
	tell_room(this_object(),
		"You hear the quiet creaking of the ropes that suspend the city.\n");
  }
  if(number == 2) {
	/* noise 3 */
	tell_room(this_object(),
		"A gentle breeze blows through the Flet.\n");
  }
  call_out("noises",30);
  return 1;
}

query_realm() { return "NT"; }
