inherit "room/room";
realm() { return "NT"; }
init() {
	::init();
	this_player()->set_fight_area();
}
reset(arg) {
	if(arg) return;
set_light(1);
short_desc=("Dark forest");
long_desc=
"Here the clearing of the path is a little narrower.  All around you are\n"+
"huge trees of the forest.  As you look up at the sun flitering through\n"+
"the leaves, an urge to save this place gets very strong.\n",
items=
({
"shadow","It looks like a ninja is hiding in the darkness",
"shadows","It looks like a ninja is hiding in the darkness",
});
dest_dir=
({
"players/dragnar/WasteLands/rooms/past/path1.c","south",
"players/dragnar/WasteLands/rooms/past/forest2.c","east",
});
}
