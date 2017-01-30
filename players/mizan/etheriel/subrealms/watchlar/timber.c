#include "std.h"
id(str) { return str == "timber"; }
short() { return "A fallen timber"; }
long() {
write("This timber has fallen from the ceiling. Your sensitive eye catch a\n"+
"glimmer of light as you pass by it. Maybe you can\n"+
"try to 'roll' it.\n");
}
init() {
	add_action("roll","roll");
	}
roll(str) {
	object gold, rock;
	if(!str) return 0;
	if(str="timber") {
	write("You struggle, and push the timber over, and find something!\n");
	say((this_player()->query_name())+" pushes a timber.\n");
	rock=clone_object("players/mizan/etheriel/subrealms/watchlar/timber1.c");
  move_object(rock, environment(this_player()));
	gold=clone_object("players/mizan/etheriel/subrealms/watchlar/amulet.c");
  move_object(gold, environment(this_player()));
	destruct(this_object());
	return 1;
}
return 0;
}
