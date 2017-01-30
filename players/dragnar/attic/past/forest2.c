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
"The forest isn't as dense here as it is to the west.  More sun is\n"+
"making it's way through the trees.  Off in the distance you can hear\n"+
"some type of siren going off.\n",
items=
({
"shadow","It looks like a ninja is hiding in the darkness",
"shadows","It looks like a ninja is hiding in the darkness",
});
dest_dir=
({
"players/dragnar/past/forest.c","south",
"players/dragnar/past/path.c","west",
});
}
