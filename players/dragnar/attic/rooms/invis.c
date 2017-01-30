short() { return 0; }
long() { return 0; }
id(str) { return 0; }

init() {
	add_action("down","down");
	}
down() {
	this_player()->move_player("via secret exit#players/dragnar/rooms/roomI");
	return 1;
	}
