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
"You are on the outskirts of the town.  Around are many houses and some\n"+
"shops and stores are directly to your east.  You can see the tower on the\n"+
"other side of the library now, it is getting so loud it is hurting your ears.\n",
items=
({
});
dest_dir=
({
"players/dragnar/WasteLands/rooms/past/town.c","east",
"players/dragnar/WasteLands/rooms/past/townrd.c","west",
});
}
