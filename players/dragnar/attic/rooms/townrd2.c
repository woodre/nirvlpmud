inherit "room/room";
init() {
	::init();
	this_player()->set_fight_area();
}
reset(arg) {
	if(arg) return;
set_light(1);
short_desc=("Wastelands town");
long_desc=
"This is the outskirts of the town.  Around you are what used to be houses\n"+
"but you see nothing of interest now.  There are chunks of pavement all\n"+
"around you, most likely from what used to be the road.  The last building\n"+
"of the town is looming in the shadows of the dust cloud to the east.\n",
items=
({
});
dest_dir=
({
"players/dragnar/rooms/town.c","east",
"players/dragnar/rooms/townrd.c","west",
});
}
