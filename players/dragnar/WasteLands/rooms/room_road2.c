inherit "room/room";
init() {
	::init();
	this_player()->set_fight_area();
}
reset(arg) {
	if(arg) return;
set_light(1);
short_desc=("town road");
long_desc=
"You stand in front of a huge bridge. You can barely see to the other side.\n" +
"Huge holes in the surface of the bridge and chunks of concrete\n" +
"scattered all over makes it look like it will be difficult to cross.\n" +
"The gorge below the river looks like it used to be a river but\n" +
"is dried up now. \n",
dest_dir=
({
"players/dragnar/WasteLands/rooms/bridge.c","cross",
"players/dragnar/WasteLands/rooms/room_road1.c","west",
});
}
