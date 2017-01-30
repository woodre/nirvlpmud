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
"Ice lines every wall and the floor even with it being so warm outside.\n"+
"The exit out is small but it is larger inside.  In frount of you are\n"+
"three passageways.  The all look the same.  Sunlight is flooding in\n"+
"from the exit and reflecting off of the ice making everything seem\n"+
"to move and sparkle.\n",
items=
({
});
dest_dir=
({
"players/dragnar/past/cave1-1.c","northeast",
"players/dragnar/past/cave2-1.c","north",
"players/dragnar/past/cave3-1.c","northwest",
"players/dragnar/past/path2.c","out",
});
}
