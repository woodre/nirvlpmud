#include "living.h"
id(str) { return str == "gate" || str == "door" || str == "doors"; }
short() { return "A worn out wooden gate"; }
long() {
write("  There is a beaten-up wooden gate here, still impressive to look at\n"+
"  despite of its abused condition. Although it looks rather massive and \n"+
"  immovable, it swings open with a light touch. You are curious to see what\n"+
"  lies beyond. Maybe you can 'enter' it.\n\n"+
"The gate is open.\n");
}
init() {
	add_action("open","open");
	add_action("close","close");
	add_action("enter","enter");
	}
open(str) {
	if(!str) return 0;
	if(str="gate") { write("The gate is already open.\n"); return 1; }
	return 0; }

close(str) {
	if(!str) return 0;
	if(str="gate") { write("Why?\n"); return 1; }
	return 0; }

enter(str) {
	if(!str) return 0;
	if(str="gate") {
	write("You float past the gate, and enter what seems to be some kind of a keep...\n");
	say((this_player()->query_name())+" pushes past the gate.\n");
	this_player()->move_player("into the keep#players/mizan/etheriel/subrealms/watchlar/k1.c");
	return 1;
	}
return 0;
}
catch_tell(str) {
	object from;
	string a,b,c;
	object next_dest;
	string next_out;
	from=this_player();
	if(!from) return 1;
	if(sscanf(str, "%s arrives.", a ,b) == 2 ) {
	call_out("lyrics", 2);
	return 1;
	}
}
lyrics() {
	say("A voice says: ...deeper inside... I'll make you mine...\n");
	return 1;
	}
