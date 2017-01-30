inherit "room/room";
realm() { return "NT"; }
init() {
	::init();
	add_action("climb","climb");
	this_player()->set_fight_area();
}
reset(arg) {
	if(arg) return;
set_light(1);
short_desc=("Ice caves");
long_desc=
"It is pitch black here.  Anything could be hiding in the darkness.\n"+
"It seems as if it could be easy to get lost in here.  There are some\n"+
"strange markings on the wall.\n",
items=
({
"markings","As you look closer the markings seem to be crevaces",
"crevaces","They look like good hand and foot holds",
});
dest_dir=
({
"players/dragnar/past/cave1-2.c","north",
"players/dragnar/past/cave1-1.c","west",
"players/dragnar/past/cave1-1.c","east",
"players/dragnar/past/cave1-2.c","northeast",
"players/dragnar/past/cave1-2.c","northwest",
"players/dragnar/past/cave1-2.c","south",
"players/dragnar/past/cave1-2.c","southeast",
"players/dragnar/past/cave1-2.c","southwest",
});
}
climb() {
	this_player()->move_player("up#players/dragnar/rooms/cave1-3.c");
	return 1;
	}
