inherit "room/room";
init() {
	::init();
	this_player()->set_fight_area();
}
reset(arg) {
	if(arg) return;
set_light(1);
short_desc=("Wasteland's library");
long_desc=
"A glass display case here has broken and glass lies all over the floor.\n"+
"Whatever was in the case is gone.  In front of you a dark staircase leads\n"+
"down into the basement of the library.\n",
dest_dir=
({
"players/dragnar/rooms/base2.c","down",
"players/dragnar/rooms/lib3.c","east",
});
}
