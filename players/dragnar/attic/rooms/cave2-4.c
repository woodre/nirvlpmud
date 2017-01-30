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
"players/dragnar/rooms/cave2-2.c","north",
"players/dragnar/rooms/cave2-2.c","south",
"players/dragnar/rooms/cave2-2.c","east",
"players/dragnar/rooms/cave2-2.c","west",
"players/dragnar/rooms/cave2-5.c","northeast",
"players/dragnar/rooms/cave2-5.c","northwest",
"players/dragnar/rooms/cave2-5.c","southeast",
"players/dragnar/rooms/cave2-5.c","southwest",
});
}
