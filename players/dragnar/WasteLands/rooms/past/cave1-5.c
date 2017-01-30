inherit "room/room";
realm() { return "NT"; }
init() {
	::init();
	this_player()->set_fight_area();
}
reset(arg) {
	if(arg) return;
set_light(1);
set_heart_beat(1);
short_desc=("Ice caves");
long_desc=
"Here the tunnel is lighted my a torch on the wall.  You can continue\n"+
"north and follow the lighted tunnel or head south.\n",
items=
({
"torch","The torch looks ancient as if it were made by primitive hands",
});
dest_dir=
({
"players/dragnar/WasteLands/rooms/past/cave1-6.c","north",
"players/dragnar/WasteLands/rooms/past/cave1-4.c","south",
});
}
heart_beat() {
	if(random (100) > 95) {
	say("The light makes your shadow dance on the ice.\n");
	}
}
