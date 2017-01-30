inherit "room/room";
realm() { return "NT"; }
init() {
	::init();
	this_player()->set_fight_area();
}
reset(arg) {
	if(arg) return;
set_light(1);
short_desc=("Wastelands town");
long_desc=
"You stand at the begining of the town.  To the north you can see the\n"+
"library, and to your east is some type of shop.  The main road turns here\n"+
"and continues south.\n",
items=
({
});
dest_dir=
({
"players/dragnar/past/shop.c","east",
"players/dragnar/past/townrd2.c","west",
"players/dragnar/past/lib.c","north",
"players/dragnar/past/town2.c","south",
});
}