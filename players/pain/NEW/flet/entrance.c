inherit "/room/room";
#include "/players/pain/color.h"

reset() {
	short_desc = BOLD+GREEN+"Entrance"+END+" to a Secret Wooded Vale";
	long_desc = "You have journeyed to the "+BOLD+GREEN+"Entrance"+END+" of the Secret Elvish Vale.\n"+
		"Tall trees surround you, reaching up towards the heavens. Soft sunlight\n"+
		"bounces off the leaves and dew and shines on your face and shoulders,\n"+
		"warming you gently. You see tracks of small animals and see birds\n"+
		"flitting from tree to tree. A path, so light it's barely recognizable\n"+
		"as such, winds its way further into the Vale.\n"+
		"You sense this is a place of peace and harmony and marvel that there\n"+
		"are still places like this surviving.\n";

	set_light(1);
	
	dest_dir = ({
		"/players/pain/NEW/tpath7", "south",
		"/players/pain/NEW/flet/fpath1", "north",
		});

	items = ({
		"tracks", "Small animal tracks cover the dirt around the path, yet absent are any tracks\n"+
			"you'd expect to find of the main inhabitants of this vale, the elves",
		"birds", "Brightly colored song birds flutter about the vale around you, filling the air\n"+
			"with their beautiful songs",
		"trees", "You see trees of all kinds about you. They are older than any you've ever seen,\n"+
			"and yet they look young and quite healthy. The inhabitants of this vale\n"+
			"obviously take care of the trees and all the rest of nature here",
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
		tell_room(this_object(),"You hear several birds whistling a beautiful song together, "+
			"as if it was orchestrated.\n");
	}
	if(number == 1) {
		/* noise 2 */
		tell_room(this_object(),"Off to your right you hear a soft rustle, and turn your head "+
			"in time to see\na pair of squirrels scamper off.\n");
	}
	if(number == 2) {
		/* noise 3 */
		tell_room(this_object(),"You hear the wind gently rustling the leaves about you.\n");
	}
	call_out("noises",20);
	return 1;
}
