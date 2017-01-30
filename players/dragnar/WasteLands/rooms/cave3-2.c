inherit "room/room";
realm() { return "NT"; }
init() {
	::init();
	this_player()->set_fight_area();
}
reset(arg) {
	if(arg) return;
set_light(1);
short_desc=("Ice caves");
long_desc=
"It is pitch black here.  Anything could be hiding in the darkness.\n"+
"It seems as if it could be easy to get lost in here.\n",
items=
({
});
dest_dir=
({
"players/dragnar/WasteLands/rooms/cave3-3.c","north",
"players/dragnar/WasteLands/rooms/cave3-1.c","south",
"players/dragnar/WasteLands/rooms/cave3-1.c","east",
"players/dragnar/WasteLands/rooms/cave3-1.c","west",
"players/dragnar/WasteLands/rooms/cave3-1.c","northwest",
"players/dragnar/WasteLands/rooms/cave3-1.c","northeast",
"players/dragnar/WasteLands/rooms/cave3-1.c","southeast",
"players/dragnar/WasteLands/rooms/cave3-1.c","southwest",
});
}
