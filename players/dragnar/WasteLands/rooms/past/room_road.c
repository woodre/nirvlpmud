inherit "room/room";
realm() { return "NT"; }
init() {
	::init();
	this_player()->set_fight_area();
}
reset(arg) {
	if(arg) return;
set_light(1);
short_desc=("Gate to town");
long_desc=
"The countryside here is very beautiful.  Small homes line the road\n"+
"with large, well kept lawns.  There doesn't seem to be anyone around\n"+
"however.  The siren in the distance seems to be getting louder.\n",
dest_dir=
({
"players/dragnar/WasteLands/rooms/past/room2.c","west",
"players/dragnar/WasteLands/rooms/past/room_road1.c","east",
});
}
