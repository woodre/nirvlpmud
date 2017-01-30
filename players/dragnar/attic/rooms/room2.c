inherit "room/room";
int gate;
init() {
	::init();
	add_action("open","open");
	add_action("east","east");
	this_player()->set_fight_area();
}
exit() {
  if(this_player())
    this_player()->clear_fight_area();
}
reset(arg) {
	if(arg) return;
	if(!arg) gate=1;
set_light(1);
short_desc=("Gate to town");
long_desc=
"As you continue closer towards the forest you notice a gate to your\n"+
"east that is closing off a broken up pavement road.  The longer\n"+
"you are here the more you wonder what happened to this land.\n",
items=
({"gate","It is blocking your way to the east.  It looks like you could open it though"
});
dest_dir=
({
"players/dragnar/rooms/arena.c","south",
"players/dragnar/rooms/room3.c","north",
});
}
open(str) {
	if(str=="gate") {
	if(gate > 2) {
	write("The gate is already open.\n");
	return 1;
	}
	gate=gate+10;
	write("The gate swings open with a loud creak.\n");
	say("The gate creaks as "+capitalize(this_player()->query_real_name())+" opens it.\n");
	return 1;
	}
}
east() {
	if(gate < 2) {
	write("The gate blocks your way.\n");
	return 1;
	}
	if(gate > 2) {
	this_player()->move_player("east#/players/dragnar/rooms/room_road.c");
	return 1;
	}
}
