inherit "room/room";
realm() { return "NT"; }
init() {
	::init();
	this_player()->set_fight_area();
}
reset(arg) {
	if(arg) return;
set_light(1);
short_desc=("town road");
long_desc=
"You stand in frount of a huge bridge.  You can barely see to the other\n"+
"side.  The river below rushes past and heads north.\n",
dest_dir=
({
"players/dragnar/past/bridge.c","cross",
"players/dragnar/past/room_road1.c","west",
});
}
