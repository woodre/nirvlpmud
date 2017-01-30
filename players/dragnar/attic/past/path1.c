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
"This is the narrowest part of the path.  Off to the west it seems to widen out\n"+
"into a clearing.  Both sides of the path are surrounded by huge trees\n"+
"that block out the hot sun.\n",
items=
({
"shadow","It looks like a ninja is hiding in the darkness",
"shadows","It looks like a ninja is hiding in the darkness",
});
dest_dir=
({
"players/dragnar/past/path.c","north",
"players/dragnar/past/path2.c","west",
});
}
