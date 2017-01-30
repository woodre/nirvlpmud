#define NAME "Zone"
#define DEST "room/south/sforst48"
id(str) { return str == "castle"; }
short() {
    return "An overgrown path through the forest north";
}

long() {
    write("An overgrown path leading to the north.\n");
}

init() {
  add_action("move", "north");
}

move() {
    object ob;
    call_other(this_player(), "move_player", "north" + "#" + "/players/zone/rooms/path1.c");
    return 1;
    write("It is not an open castle.\n");
}

reset(arg) {
    if (arg)
	return;
    move_object(this_object(), DEST);
}
is_castle(){ return 1; }
