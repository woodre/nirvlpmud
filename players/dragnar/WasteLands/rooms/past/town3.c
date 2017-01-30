inherit "room/room";
realm() { return "NT"; }
init() {
	::init();
	this_player()->set_fight_area();
}
reset(arg) {
	if(arg) return;
set_light(5);
short_desc=("Wasteland's Town");
long_desc=
"Here the road turns toward the east again, and passes right in frount of a \n"+
"huge tower.  On the top of the tower is a siren that is almost deafening\n"+
"it is so loud.\n",
items=
({
});
dest_dir=
({
"players/dragnar/WasteLands/rooms/past/town2.c","north",
"players/dragnar/WasteLands/rooms/past/town4.c","east",
});
}
