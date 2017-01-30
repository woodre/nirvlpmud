inherit "room/room";
init() {
	::init();
	this_player()->set_fight_area();
}
reset(arg) {
	if(arg) return;
set_light(1);
short_desc=("Ice caves");
long_desc=
"It is very dark and difficult to see, but the surroundings look familiar\n"+
"to you, only they seem different somehow too.\n",
items=
({
});
dest_dir=
({
"players/dragnar/past/cave1-9.c","south",
});
}
