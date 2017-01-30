inherit "room/room";
init() {
	::init();
}
reset(arg) {
	if(arg) return;
set_light(1);
short_desc=("Road to a Temple");
long_desc=
"You stand at the begining of a dirt road.  It seems to have been used\n"+
"recently and is free of any rubble.  Along the sides of the road spears\n"+
"have been lodged into the dirt, their tips pointed toward the dark\n"+
"Wastelands sky.  A head of a dead warrior is placed on each tip, their\n"+
"blank eyes seem to stare right through you.\n",
dest_dir=
({
"players/dragnar/rooms/healshop.c","west",
"players/dragnar/guild/rooms/road2.c","east",
});
}
