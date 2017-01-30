
id(str) { return str=="rock" || str=="ice"; }
reset () {}
short() {
	return "A rock of ice";
}
long() {
write("As you gaze at the rock it seems like you can almost see through\n"+
"it.  You have a sudden urge to touch it.\n");
}
init() {
	add_action("touch","touch");
	}
touch() {
	this_player()->move_player("trough the rock#players/dragnar/rooms/cave1-1.c");
	return 1;
}
get() {
	tell_object(this_player(), "It is too heavy.\n");
	return 0;
	}
query_weight() { return 0; }
query_value() { return 5000; }
