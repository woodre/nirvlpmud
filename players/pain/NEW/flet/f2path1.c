inherit "/room/room";
#include "/players/pain/color.h"

reset() {
	short_desc = "Deeper into the "+BOLD+GREEN+"Vale"+END;
	long_desc = "As you venture deeper into this part of the "+BOLD+GREEN+"Vale"+END+",\n"+
		"it seems to get brighter. The trees are just as dense, yet they are\n"+
		"different here than they were, and are much more beautiful. The sunlight\n"+
		"streams down through the trees, reflected off their leaves and bark,\n"+
		"covering the forest floor with a warm glow. The path seems to be more\n"+
		"well defined here, as if there was a reason its creators wanted to be\n"+
		"sure that no one would lose it.\n";

	set_light(1);
	
	dest_dir = ({
		"/players/pain/NEW/flet/fpath1", "southwest",
		"/players/pain/NEW/flet/f2path2", "north",
		});

	items = ({
		"bark","Beautiful, silver bark, unlike any you've ever seen",
		"trees","Handsome and strong trees, unique to this vale",
		"leaves","Broad silver-green leaves which reflect light quite easily",
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
		tell_room(this_object(),"You hear the quiet rustling of the wind through the leaves.\n");
	}
	if(number == 1) {
		/* noise 2 */
		tell_room(this_object(),"Off to the north you hear quiet giggling and merriment.\n");
	}
	if(number == 2) {
		/* noise 3 */
		tell_room(this_object(),"You think you hear mvoement high up in the trees.\n"+
			"Maybe it was just a bird?\n");
	}
	call_out("noises",10);
	return 1;
}
