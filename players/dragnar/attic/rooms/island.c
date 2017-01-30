inherit "room/room";
	object dog;
init() {
	::init();
	this_player()->set_fight_area();
}
reset(arg) {
	dog=clone_object("/players/dragnar/mons/dog.c");
	move_object(dog, this_object());
	if(arg) return;
set_light(5);
short_desc=("Island of the temple");
long_desc=
"You climb up the side of the gorge to an island of darkness.  Everything\n" +
"around you is frightning.  The life that used to be here\n" +
"is replaced with rubble and bones everywhere.  To the north you can make\n" +
"out some sort of building.\n",
dest_dir=
({
"players/dragnar/rooms/islande.c","east",
"players/dragnar/rooms/islandw.c","west",
"players/dragnar/rooms/island2.c","north",
"players/dragnar/rooms/gorge3","down",
});
}
