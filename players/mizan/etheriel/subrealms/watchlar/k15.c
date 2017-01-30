#include "std.h"
object mirror, etheriel, bed;
short() { return "Etheriel's Bedroom [south]"; }
long() {
write(
"	You push open the door, and glide into the room. You are slightly\n"+
"  impressed by what you see. The room is decorated spelendidly, with \n"+
"  various items of jewelry and such lying about. Although most everything\n"+
"  is worn and deteriorated, all the items in the room seem to be\n"+
"  untouched.\n"+
"    There is one obvious exit: south\n");
}

reset(arg) {
	if(!arg) {
	
	if(!mirror || !present(mirror)) {
	mirror=clone_object("players/mizan/etheriel/subrealms/watchlar/mirror.c");
	move_object(mirror, this_object());
	}
    }
}

init() {
	add_action("place","place");
	add_action("south","south");
	}

south() {
	this_player()->move_player("south#players/mizan/etheriel/subrealms/watchlar/k12.c");
	return 1;
	}
place(str) {
	object portal, defi;
	if(!str) return 0;
	if(str=="shard into mirror") {
	command("drop zmxncbv", this_player());
	defi=present("zmxncbv");
	if(!defi) return 0;
	destruct(present(defi));
	destruct(present("mirror"));
	portal=clone_object("players/mizan/etheriel/subrealms/watchlar/mirror2.c");
	move_object(portal, this_object());
	write("You place the glass into the mirror, and it fits just right!\n");
	say((this_player()->query_name())+" places a shard of glass into  into the mirror.\n");
	return 1;
	}
}
