inherit "room/room";
realm() { return "NT"; }
init() {
	::init();
	this_player()->set_fight_area();
}
reset(arg) {
	if(arg) return;
set_light(1);
short_desc=("Dark forest");
long_desc=
"To the south you can see some type of gate, and off to the east\n"+
"you can hear a river.  The path goes north and south from here.\n",
items=
({"shadow","It looks like a ninja is hiding in the darkness",
"shadows","It looks like a ninja is hiding in the darkness",
});
dest_dir=
({
"players/dragnar/past/room3.c","south",
"players/dragnar/past/forest2.c","north",
});
}
