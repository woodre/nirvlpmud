inherit "/room/room";
#include "/players/pain/color.h"

reset() {
  short_desc = "Entrance to a "+BOLD+GREEN+"Grove"+END;
  long_desc = 
	"You stand at the entrance to a quiet, ancient "+BOLD+GREEN+"Grove"+END+" of\n"+
 	"sacred Mallorn trees. Two trees stand close to either side\n"+
	"of the path, their branches arching together to form a sort\n"+
	"of archway for you to enter under. There are no special\n"+
	"markings or signs denoting it as such, but you feel certain\n"+
	"that the mysterious "+BOLD+GREEN+"Elven Flet"+END+" lies ahead.\n";

  set_light(1);
	
  dest_dir = ({
	"/players/pain/NEW/flet/fpath2", "southeast",
	"/players/pain/NEW/flet/grove1", "west",
	});

  items = ({
	"trees", "The oldest Mallorn trees in the vale surround you on all sides",
	"archway", "Thick limbs from either tree arch over the pathway",
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
		"You feel the mystical energies from the "+BOLD+GREEN+
		"grove"+END+" beckoning you.\n");
  }
  if(number == 1) {
	/* noise 2 */
	tell_room(this_object(),
		"You find it curious that you hear no animal sounds here.\n");
  }
  if(number == 2) {
	/* noise 3 */
	tell_room(this_object(),
		"A light breeze sweeps over the path from the grove.\n");
  }
  call_out("noises",30);
  return 1;
}

