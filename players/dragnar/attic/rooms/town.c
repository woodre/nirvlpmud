inherit "room/room";
int x;
init() {
	::init();
	this_player()->set_fight_area();
}
reset(arg) {
	if(arg) return;
	if(!arg) x=0;
set_light(1);
short_desc=("Wastelands town");
long_desc=
"You stand at the begining of the town.  To the north you can see the\n"+
"library, but the other buildings seem to be in ruins.  To the\n"+
"east you can see some kind of old shop.\n",
items=
({
});
dest_dir=
({
"players/dragnar/rooms/shop.c","east",
"players/dragnar/rooms/townrd2.c","west",
"players/dragnar/rooms/lib.c","north",
"players/dragnar/rooms/town2.c","south",
});
}
