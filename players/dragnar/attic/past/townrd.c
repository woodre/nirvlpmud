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
"Farther off to the east the town is drawing very close.  To the west\n"+
"is a huge bridge that crosses a river.  As you stand on the road with\n"+
"all of the houses around you, you begin to wonder why it is that no one\n"+
"is out on such a beautiful day.  The air siren is getting very loud now,\n"+
"and it's erie shrill sound may have some answers within it.\n",
items=
({
});
dest_dir=
({
"players/dragnar/past/townrd2.c","east",
"players/dragnar/past/bridge2.c","west",
});
}
