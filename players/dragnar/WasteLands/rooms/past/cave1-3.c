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
"As you climb up the wall you notice light somewhere above.  The ice is\n"+
"very slippery and you wonder if maybe you should climb back down.\n",
items=
({
});
dest_dir=
({
"players/dragnar/WasteLands/rooms/past/cave1-2.c","down",
"players/dragnar/WasteLands/rooms/past/cave1-4.c","up",
});
}
