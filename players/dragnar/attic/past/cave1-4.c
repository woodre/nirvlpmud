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
"Here the tunnel is lighted by a torch on the wall.  Looking down over\n"+
"the edge everything is lost in blackness.  You can climb down or follow\n"+
"the tunnel toward the light.\n",
items=
({
"torch","The torch looks ancient as if it were made by primitive hands",
});
dest_dir=
({
"players/dragnar/past/cave1-5.c","north",
"players/dragnar/past/cave1-3.c","down",
});
}
heart_beat() {
	if(random (100) > 95) {
	say("The light makes your shadow dance on the ice.\n");
	}
}
