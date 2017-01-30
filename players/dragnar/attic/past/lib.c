inherit "room/room";
realm() { return "NT"; }
int x,y;
init() {
	::init();
	this_player()->set_fight_area();
	add_action("open","open");
	add_action("enter"); add_verb("enter");
}
reset(arg) {
	if(arg) return;
	if(!arg) x=1;
y=1;
set_light(5);
short_desc=("Entrance to the Wasteland's Library");
long_desc=
"Before you is the library.  It was built in the 1950's according to the\n"+
"concrete base of the building.  It looks very well built and almost new even\n"+
"though it is an older building.  The huge doors leading inside seem\n"+
"to be closed and locked.\n",
items=
({
"door","It looks heavy but it looks like you could open it"
});
dest_dir=
({
"players/dragnar/past/town.c","south",
});
}
open(str) {
	if(str=="door"){
	write("The door is locked.\n");
	return 1;
	}
}
enter() {
	if(x > 2) {
	call_other(this_player(),"move_player","enter#/players/dragnar/rooms/lib2.c");
	return 1;
	}
	else if(x < 2) {
	write("The door isn't open.\n");
	return 1;
	}
}
