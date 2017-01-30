inherit "room/room";
realm() { return "NT"; }
init() {
	::init();
	this_player()->set_fight_area();
}
reset(arg) {
	if(arg) return;
set_light(1);
short_desc=("town road");
long_desc=
"As you get closer to the bridge you can see that it is very large\n"+
"and looks rather new.  To the north and south are gravesyards.  Rows\n"+
"and rows of headstones line the grassy hills.  Some have newly\n"+
"placed flowers on them.\n",
dest_dir=
({
"players/dragnar/WasteLands/rooms/past/room_road2.c","east",
"players/dragnar/WasteLands/rooms/past/room_road.c","west",
});
}
