inherit "room/room";
#define TO this_object()

init() {
	::init();
	add_action("enter","enter");
	this_player()->set_fight_area();
}
exit() {
  if(this_player())
    this_player()->set_fight_area();
}

reset(arg) {
if(!present("ninja")) { move_object(clone_object("players/dragnar/WasteLands/mons/master"),TO); }

	if(arg) return;

set_light(1);
short_desc=("Dark forest");
long_desc=
"As you enter the clearing you notice the ice cave in the center of\n"+
"the clearing.  It looks very dark inside and ice lines the outside\n"+
"of the entrance.  The only other way to go is back on the path.\n",
items=
({
"ice cave","The entrance looks small but you could enter it...if you dare",
"cave", "The entrance looks small but you could enter it...if you dare",
});
dest_dir=
({
"/players/dragnar/WasteLands/rooms/path1","east",
});
}
enter() {
	if(present("ninja")){
	write("Master ninja says: I cannot let you enter.\n");
	return 1;
	}
	this_player()->move_player("into the cave#players/dragnar/WasteLands/rooms/cave");
	return 1;
}
