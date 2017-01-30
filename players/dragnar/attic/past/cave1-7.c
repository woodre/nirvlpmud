inherit "room/room";
realm() { return "NT"; }
int x;
init() {
	::init();
	add_action("pull","pull");
	add_action("crawl","crawl");
	this_player()->set_fight_area();
}
reset(arg) {
	if(arg) return;
	if(!arg) x=1;
set_light(1);
set_heart_beat(1);
short_desc=("Ice Caves");
long_desc=
"The tunnel is lighted by a torch on the wall.  Here the tunnel seems to\n"+
"just stop and become a dead end.  The only way seems to be back towards\n"+
"to the south.\n",
items=
({
"torch","It's handle is wooden, it looks like a lever you could pull",
});
dest_dir=
({
"players/dragnar/past/cave1-6.c","south",
});
}
heart_beat() {
	if(random (100) > 95) {
	say("The light makes your shadow dance on the ice.\n");
	}
}
pull() {
	x=x+10;
	write("You hear a loud noise and a part of the wall moves slightly\n"+
"and leaves a hole.  It looks small but maybe you could crawl through.\n");
	return 1;
}
crawl(str) {
	if(str=="hole"){
	if(x < 2) {
	write("There is no hole here.\n");
	return 1;
	}
	if( x > 2) {
	write("You bend over and crawl through the hole.\n");
	this_player()->move_player("hole#/players/dragnar/rooms/cave1-8.c");
	return 1;
	}
	}
}
