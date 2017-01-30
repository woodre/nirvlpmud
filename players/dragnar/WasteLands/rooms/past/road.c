inherit "room/room";
init() {
	::init();
	this_player()->set_fight_area();
}
reset(arg) {
	if(arg) return;
set_light(1);
short_desc=("Gate to town");
long_desc=
	"You are at the begining of a torn up road.  There are chunks of pavement\n" +
"everywhere and rubble all over the land.  It looks as if there was a great\n" +
"battle here.  Off to the east you can see the road leads to a bridge.\n",
dest_dir=
({
"players/dragnar/WasteLands/rooms/room2.c","west",
"players/dragnar/WasteLands/rooms/room_road1.c","east",
});
}
