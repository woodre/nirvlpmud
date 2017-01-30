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
"To your east the town seems to go on forever.  You can see nothing different\n"+
"about that part of town, lots of buildings and no people in sight.\n"+
"To your north is a large building made of mostly windows.  A sign in\n"+
"the green grass reads: 'US Government'\n",
items=
({
});
dest_dir=
({
"players/dragnar/past/town5.c","north",
"players/dragnar/past/town3.c","west",
});
}
