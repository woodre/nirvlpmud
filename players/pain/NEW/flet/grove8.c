inherit "/room/room";
#include "/players/pain/color.h"

reset() {
  short_desc = "A "+BOLD+GREEN+"Grove"+END;
  long_desc = "You stand in the midst of a quiet, ancient "+BOLD+GREEN+"grove"+END+" in the\n"+
	"middle of the "+BOLD+GREEN+"Elven Vale"+END+". Mystery shrouds this place and\n"+
	"you can't help but wonder if you'll find the entrance to the "+BOLD+GREEN+"Elven Flet"+END+" here.\n"+
	"The trees are thick about you, and there is no real path other than that\n"+
	"which leads back to the vale. It is cool and damp here, the sunlight is blocked\n"+
	"from up above by the thick canopy of trees. You sense a definate energy here.\n";

  set_light(1);
	
  dest_dir = ({
	"/players/pain/NEW/flet/grove1", "north",
	"/players/pain/NEW/flet/grove7", "west",
	"/players/pain/NEW/flet/grove_c", "northwest",
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
  if(call_other("/players/pain/NEW/flet/f2path3","query_murder")) {
	 if(number == 0) {
		/* noise 1 */
		tell_room(this_object(),
			"You can sense that something is wrong here.\nThe whole grove is mourning.\n");
	}
	if(number == 1) {
		/* noise 2 */
		tell_room(this_object(),
			"You feel a strong angry energy surrounding you.\n");
	}
	if(number == 2) {
		/* noise 3 */
		tell_room(this_object(),
			"The whole grove seems to echo, "+BOLD+RED+"M U R D E R"+END+".\n");
	}
  }
else {
   if(number == 0) {
	/* noise 1 */
	tell_room(this_object(),
		"You think you hear noise eminating from the trees above you.\n");
  }
  if(number == 1) {
	/* noise 2 */
	tell_room(this_object(),
		"A mysterious energy surrounds you, beckoning you deeper into the grove.\n");
  }
  if(number == 2) {
	/* noise 3 */
	tell_room(this_object(),
		"You think you hear something creak high above you.\n");
  }
}
  call_out("noises",10);
  return 1;
}

