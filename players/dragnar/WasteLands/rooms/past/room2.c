inherit "room/room";
realm() { return "NT"; }
int gate;
init() {
	::init();
	add_action("open","open");
	add_action("east","east");
	this_player()->set_fight_area();
}
reset(arg) {
	if(arg) return;
	if(!arg) gate=1;
set_light(1);
short_desc=("Gate to town");
long_desc=
"A gate is here closing off a pavement road.  There is a sign next\n"+
"to the gate.  As you look down the road you can see a bridge off in\n"+
"the distance.\n",
items=
({"gate","It is blocking your way to the east.  It looks like you could open it though",
"sign","\n\n\nCity of Thornwood 10 mi =====>"
});
dest_dir=
({
"players/dragnar/WasteLands/rooms/past/room3.c","north",
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
	this_player()->move_player("east#/players/dragnar/WasteLands/rooms/past/room_road.c");
	return 1;
	}
}
