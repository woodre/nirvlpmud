inherit "room/room";
realm() { return "NT"; }
int x;
init() {
	::init();
/* quest change, moved entrance to cave1-8 go cave3-4  -Eurale 4/5/97
	add_action("pull","pull");
	add_action("crawl","crawl");
*/
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
"just stop and become a dead end.  The only way seems to be back the\n"+
"way that you came.\n",
items=
({
/*
"torch","It's handle is wooden, it looks like a lever you could pull",
*/
  "torch","A small lighted torch",
});
dest_dir=
({
"players/dragnar/WasteLands/rooms/cave1-6.c","south",
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
crawl(){
	if(x < 2) {
	write("There is no hole to crawl through here.\n");
	return 1;
	}
	if( x > 2) {
	write("You bend over and crawl through the hole.\n");
	this_player()->move_player("hole#/players/dragnar/WasteLands/rooms/cave1-8.c");
	return 1;
	}
}
