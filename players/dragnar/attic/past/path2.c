inherit "room/room";
realm() { return "NT"; }
init() {
	::init();
	add_action("enter","enter");
	this_player()->set_fight_area();
}
reset(arg) {
	if(arg) return;
set_light(1);
short_desc=("Dark forest");
long_desc=
"As you stand in the clearing you are taken back by it's beauty.\n"+
"Flowers fill the clearing and the lush green trees sway in the wind on\n"+
"the edge where the forest begins.  In the center is an entrance into the ice\n"+
"caves.  Everything seems very peaceful, as if nothing could ever go\n"+
"wrong in this place.\n",
items=
({
"entrance","It looks small, but you probably could enter",
"ice cave","The entrance looks small but you could enter",
"cave", "The entrance looks small but you could enter",
});
dest_dir=
({
"players/dragnar/past/path1.c","east",
});
}
enter() {
	if(present("ninja")){
	write("Master ninja says: I cannot let you enter.\n");
	return 1;
	}
	this_player()->move_player("into the cave#players/dragnar/past/cave.c");
	return 1;
}
