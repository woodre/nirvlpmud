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
"You are still on what used to be the main road of the town.  All around you\n"+
"are buildings that are just piles of rubble.  The Library is to the\n"+
"north of you, and to the west you can make out the top of a bridge.\n",
items=
({
});
dest_dir=
({
"players/dragnar/rooms/town.c","north",
"players/dragnar/rooms/town3.c","south",
});
}
