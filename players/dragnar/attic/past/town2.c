inherit "room/room";
realm() { return "NT"; }
init() {
	::init();
	this_player()->set_fight_area();
}
reset(arg) {
	if(arg) return;
set_light(1);
short_desc=("Wastelands town");
long_desc=
"You are still on the main road of the town.  All around you are huge \n"+
"buildings.  The library is to the north of you and you can make out\n"+
"the top of a bridge to the northwest.\n",
items=
({
});
dest_dir=
({
"players/dragnar/past/town.c","north",
"players/dragnar/past/town3.c","south",
});
}
