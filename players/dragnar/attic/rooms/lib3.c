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
"There are books scattered throughout the room.  Parts of ceiling have\n"+
"fallen to the floor and some of the shelves are tipped over.  On the\n"+
"north end of the room is a open door that is swaying on its hinges.\n",
dest_dir=
({
"players/dragnar/rooms/lib2.c","east",
"players/dragnar/rooms/base.c","west",
"players/dragnar/rooms/lib4.c","north",
});
}
