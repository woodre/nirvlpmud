inherit "room/room";
init() {
	::init();
	this_player()->set_fight_area();
}
reset(arg) {
	if(arg) return;
set_light(1);
short_desc=("Gorge");
long_desc=
"Right in frount of you now is the island.  Standing at the bottom\n" +
"of the gorge like this makes it look steep, but it looks like you could\n" +
"climb up the side onto to the island.\n",
dest_dir=
({
"players/dragnar/WasteLands/rooms/island.c","climb",
"players/dragnar/WasteLands/rooms/gorge2.c","south",
});
}
