short() { return 0; }
long() { return 0; }
id(str) { return 0; }

init() {
	add_action("jump","jump");
	}
jump() {
	this_player()->heal_self(-50);
	tell_object(this_player(), "You run to the side of the bridge and jump!\n\n" +
"\n\n\n\n\n\n\n\n" +
"You fall to the ground below and crumple to your knees.\n");
	tell_object(this_player(), "You lie writhing on the ground in PAIN!!!.\n");
	tell_object(this_player(), "[HPS]="+this_player()->query_hp()+" \n");
tell_object(this_player(), "\n");
	this_player()->move_player("via secret exit#players/dragnar/rooms/gorge.c");
	return 1;
	}
