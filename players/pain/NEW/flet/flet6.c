inherit "room/room";
#include "/players/pain/color.h"

reset() {
	short_desc = "The "+BOLD+GREEN+"Elven Flet"+END;
	long_desc = "You are standing high above the Elven Vale on a walkway of the\n"+
		BOLD+GREEN+"Elven Flet"+END+". This walkway is strung between several huge, old\n"+
		"Mallorn trees. Each of the trees is approximately 40 feet in diameter.\n"+
		"This portion of the walkway lies just before another platform to the north-\n"+
		"east. The walkway stretches behind you to the south towards another platform.\n";

	set_light(1);
	
	dest_dir = ({
		"/players/pain/NEW/flet/flet5", "south",
/*  removed exit as there is no room flet7 - eurale
		"/players/pain/NEW/flet/flet7", "northeast",
*/
		});

	items = ({
		"walkway", "A walkway composed of Mallorn wood and rope stretches between the\n"+
			"trees beneath your feet",
		"platform", "A huge wooden platform bearing up elven dwellings and shops",
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
			"You hear the clanking of metal coming from the platform to the northeast.\n");
	}
	if(number == 1) {
		/* noise 2 */
		tell_room(this_object(),
			"Soft elven voices murmur through the trees.\n");
	}
	if(number == 2) {
		/* noise 3 */
		tell_room(this_object(),
			"You hear the creaking of the walkway beneath your feet as you walk onwards.\n");
	}
	call_out("noises",10);
	return 1;
}
