inherit "room/room";
object cult, master;
init() {
	::init();
	this_player()->set_fight_area();
}
reset(arg) {
	master=clone_object("/players/dragnar/mons/cultmaster2.c");
	move_object(master, this_object());
	if(arg) return;
set_light(5);
short_desc=("Wasteland's library");
long_desc=
"This is the small private space of the cult leader.  There are\n"+
"candles lighted all over the room that cast a strange glow all\n"+
"about.  The room is bare, almost as if it were nothing more than\n"+
"a hiding spot.\n",
dest_dir=
({
"players/dragnar/rooms/lib10.c","out",
});
}
