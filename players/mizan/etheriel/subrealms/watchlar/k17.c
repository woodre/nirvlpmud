#include "std.h"
object mirror, etheriel, bed;
short() { return "Inside the Mirror [no exits]"; }
long() {
write("	You are inside a world of mirrors, seemingly infinite in size\n"+
"  because of the myriads of reflections that you see. However, it is only\n"+
"  a cubicle in size, and there is a person here, and some sparse furnishings.\n"+
"  It almost has a two-dimensional feel, this room...\n");
}

query_realm() { return "ND"; }
reset(arg) {
	if(!arg) {
	
/*
	if(!etheriel || !living(etheriel)) {
	etheriel=clone_object("players/mizan/beasties/retheriel.c");
	move_object(etheriel, this_object());
	}
*/
	if(!bed || !present(bed)) {
	bed=clone_object("players/mizan/etheriel/subrealms/watchlar/bed.c");
	move_object(bed, this_object());
	}
	if(!mirror || !present(mirror)) {
	mirror=clone_object("players/mizan/etheriel/subrealms/watchlar/mirror1.c");
	move_object(mirror, this_object());
	}
    }
}
