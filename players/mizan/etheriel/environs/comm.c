#include "std.h"
id(str) { return str == "ball"; }
short() { return "A glowing crystal ball"; }
long() {
write("This is a glowing crystal ball, emitting a faint blue aura.\n"+
"There is a raised button on it. It looks like you can 'squeeze ball'\n");
}
init() {
	add_action("squeeze","squeeze");
	}
squeeze(str) {
	if(!str) return 0;
	if(str=="ball") {
	write_file("/players/mizan/logs/area.log", (this_player()->query_name())+" SB\n");
	write("You squeeze the ball and something odd happens...\n\n"+
"You can see through your hands!\n"+
"Suddenly, you feel weak, as if you are DYING!\n\n"+
"But then, just as you are about to fade into nothing, reality snaps back\n"+
"into click. However, you are in a different place.\n\n"+
"You hear: 'Uckier? what's going on?? Do you copy?? This is Don...\n\n");
	this_player()->move_player("in a blinding flash#players/mizan/castle/s1.c");
	return 1;
	}
}
