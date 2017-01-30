inherit "room/room";
object sci;
init() {
	::init();
	this_player()->set_fight_area();
}
reset(arg) {
	if(arg) return 0;
	sci=clone_object("/players/dragnar/WasteLands/mons/sci.c");
	move_object(sci, this_object());
set_light(1);
short_desc=("Wastelands town");
long_desc=
"It looks almost like someone has been living here.  There is a campfire\n"+
"toward the corner of one room, and some pieces of plastic and\n"+
"sheeting are put up like it was meant to be a barrier.  Farther\n"+
"back in the room is pure darkness where the light from the coals can't\n"+
"reach.  The wasteland's daylight isn't much different from its night.\n",
items=
({
"darkness","You strain your eyes and notice a man hiding in the darkness",
});
dest_dir=
({
"players/dragnar/WasteLands/rooms/town4.c","south",
});
}
