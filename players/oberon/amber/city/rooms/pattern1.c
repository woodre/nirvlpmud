#include "/sys/ansi.h"
#include "/sys/lib.h"
inherit "/room/room";

reset(arg) {
	::reset(arg);
	if(arg) return;
	set_light(1);
	short_desc = "In a field";
	long_desc =
		"Standing in a field. There is a large circular stone slab on the\n"+
		"ground. Upon it, there is a carved pattern. The pattern looks to\n"+
		"be a large spiderweb-like maze. As you gaze at the pattern, you\n"+
		"feel the urge to walk it. A dirt path leads north towards a large\n"+
		"city.\n";
	items = ({
		"stone","The stone itself is fairly basic",
		"slab","The stone itself is fairly basic",
		"pattern","There seems to be something at the center,\nbut you can't tell what",
		"maze","The pattern on the stone looks like some sort of maze",
		"path","A dirt path leading north",
		"city","What luck! It appears to be the City of Amber",
	});
	dest_dir = ({
		"/players/oberon/amber/city/rooms/outside","north",
	});
}

init() {
	::init();
	add_action("travel_pattern","walk");
}

travel_pattern(arg) {
	if(!arg || arg != "pattern") {
		write("The pattern feels your desire to walk it!\n");
		return 1;
	}
	else {
		string gender;
		if(this_player()->query_gender() == "male") gender = "he";
		else gender = "she";
		write("You step onto the Pattern, and slowly fade.\n");
		say(this_player()->query_name()+" slowly fades from view as "+gender+" walks the Pattern.");
		move_object(this_player(), "/players/boltar/santaland/cavein.c");
		return 1;
	}
}
