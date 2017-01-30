inherit "room/room";
realm() { return "NT"; }
init() {
	::init();
	this_player()->set_fight_area();
}
reset(arg) {
set_light(1);
short_desc=("Dark forest");
long_desc=
"This is the entrance to the forest.  Farther to the south are grasslands.\n"+
"To the north the trees seem to get very dense.\n",
items=
({"shadow","It looks like a ninja is hiding in the darkness",
"shadows","It looks like a ninja is hiding in the darkness",
});
dest_dir=
({
"players/dragnar/WasteLands/rooms/past/room2.c","south",
"players/dragnar/WasteLands/rooms/past/forest.c","north",
});
}
