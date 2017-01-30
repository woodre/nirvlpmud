#include "/sys/ansi.h"
#include "/sys/lib.h"
inherit "/room/room";

int i;

reset(arg) {
	::reset(arg);
	if(arg) return;
	set_light(1);
	short_desc = "Eastern Guard Shack";
	long_desc =
		"The guard house is made mostly of stone. The walls are a dull grey\n"+
		"stone, while the floor is a nice cobblestone. Various racks of armor\n"+
		"and weapons line the walls. There is a cot in the corner of the room,\n"+
		"and chairs for the guards to rest on. To the west leads back to\n"+
		"Castle Way.\n";
	dest_dir = ({
		"/players/oberon/amber/city/rooms/castleway1","west",
	});

	for(i = random(2); i >= 0; i--) {
		move_object(clone_object("/players/oberon/amber/city/mob/gateguard.c"), this_object());
	}
}
