inherit "room/room";
init() {
	::init();
	this_player()->set_fight_area();
}
reset(arg) {
	if(arg) return;
set_light(0);
short_desc=("Wasteland's library");
long_desc=
"It's so dark in the basement you can't see what is down there.  You have\n"+
"a sudden urge to get as far from the basement as you can.\n",
dest_dir=
({
"players/dragnar/rooms/Ebase3.c","down",
"players/dragnar/rooms/base.c","up",
});
}
