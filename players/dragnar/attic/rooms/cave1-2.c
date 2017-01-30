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
"markings","As you look closer the markings seem to be crevices",
"crevices","They look like good hand and foot holds",
});
dest_dir=
({
"players/dragnar/rooms/cave1-1.c","north",
"players/dragnar/rooms/cave1-1.c","west",
"players/dragnar/rooms/cave1-1.c","east",
"players/dragnar/rooms/cave1-1.c","northeast",
"players/dragnar/rooms/cave1-1.c","northwest",
"players/dragnar/rooms/cave1-1.c","south",
"players/dragnar/rooms/cave1-1.c","southeast",
"players/dragnar/rooms/cave1-1.c","southwest",
});
}
climb() {
	this_player()->move_player("up#players/dragnar/rooms/cave1-3.c");
	return 1;
	}
