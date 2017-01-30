inherit "/room/room";
#include "/players/pain/color.h"

reset() {
	short_desc = 
	long_desc =

	set_light(1);
	
	dest_dir = ({

		});

	items = ({

		});
	
	call_out("noises",10);
}

init() {
	::init();
}

noises() {
int number;

	number = random(3);
	if(number) == 0) {
		/* noise 1 */
		tell_room("\n");
	}
	if(number == 1) {
		/* noise 2 */
		tell_room("\n");
	}
	if(number == 2) {
		/* noise 3 */
		tell_room("\n");
	}
	call_out("noises",10);
	return 1;
}
