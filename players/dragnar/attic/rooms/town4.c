inherit "room/room";
init() {
	::init();
	this_player()->set_fight_area();
}
reset(arg) {
	if(arg) return;
set_light(1);
short_desc=("Wastelands town");
long_desc=
"To your east the town seems to be a huge graveyard that goes on forever.\n"+
"You can see nothing different about that part of town.  To the north\n"+
"is the ruins of a type of government building according to a sign\n"+
"laying on the ground.  The only other direction you can go is past\n"+
"the tower to the west.\n",
items=
({
});
dest_dir=
({
"players/dragnar/rooms/Etown5.c","north",
"players/dragnar/rooms/town3.c","west",
});
}
