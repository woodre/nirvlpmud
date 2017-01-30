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
"The cave ceiling here gets very high.  It is so dark that you can't make\n"+
"out just how high it goes.  Every step seems to echo a hundred times.\n"+
"To the north you see some kind of light.\n",
items=
({
});
dest_dir=
({
"players/dragnar/past/cave1-9.c","north",
"players/dragnar/past/cave1-7.c","out",
});
}
