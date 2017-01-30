inherit "/room/room";
#include "/players/pain/color.h"

reset() {
	short_desc = "A quiet, wooded "+BOLD+GREEN+"path"+END;
	long_desc = "Continuing further into the vale, you reach a fork in the "+BOLD+GREEN+"path"+END+".\n"+
		"You stand in the middle of a slight clearing, the sun shines brighter here,\n"+
		"warming you more to compensate for the chilly morning. As you revel in the\n"+
		"beautiful morning you stand in awe of the immense beauty of this vale and\n"+
		"wonder about the mythical elves that supposedly inhabit it.\n";

	set_light(1);
	
	dest_dir = ({
		"/players/pain/NEW/flet/entrance", "south",
		"/players/pain/NEW/flet/fpath2", "northwest",
		"/players/pain/NEW/flet/f2path1", "northeast",
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
		tell_room(this_object(),"You hear the birds sing and flit from tree to tree.\n");
	}
	if(number == 1) {
		/* noise 2 */
		tell_room(this_object(),"You hear high-pitched giggling far off to the northeast.\n");
	}
	if(number == 2) {
		/* noise 3 */
		tell_room(this_object(),"You hear a rustling in the trees and get the feeling that "+
			"you're being watched.\n");
	}
	call_out("noises",10);
	return 1;
}
