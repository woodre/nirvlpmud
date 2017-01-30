inherit "room/room";
realm() { return "NT"; }
init() {
	::init();
	this_player()->set_fight_area();
}
reset(arg) {
	if(arg) return;
set_light(10);
short_desc=("Gate to town");
long_desc=
"As you cross the bridge you can see the water rushing past on it's\n"+
"way to the north.  Farther to the east you can see the skyline of a\n"+
"town in the bright days sunshine.\n",
items=
dest_dir=
({
"players/dragnar/WasteLands/rooms/past/bridge2.c","east",
"players/dragnar/WasteLands/rooms/past/room_road2.c","west",
});
}
