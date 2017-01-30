#include <ansi.h>
#include "/sys/lib.h"
inherit "/room/room";

int gate_open, gate_locked;

reset(arg) {
	::reset(arg);
	if(arg) return;
	set_gate(3);
	set_light(1);
	short_desc = "Outside the City of Amber";
	long_desc =
		"A long road leads to a huge gate to the north. Along the sides of\n"+
		"the road are sparse trees, with shrubbery covering the ground. The\n"+
		"large walls block view of what's behind them, though the sounds of\n"+
		"a busy city can be heard beyond. There is a stone guard house to\n"+
		"the west.\n";
	items = ({
		"road","The road you are currently standing on",
		"trees","Fairly large, normal looking trees",
		"shrubbery","It's slightly higher then the other shrubbery, creating a layer affect",
		"walls","Very tall walls, to keep people out of the city",
		"house","It seems to be where guards go to rest",
		"gate","A large gate to the north appears large enough for\n"+
			"an army to easily march through",
	});
	dest_dir = ({
		"/players/oberon/amber/city/rooms/southgate","north",
		"/players/oberon/amber/city/rooms/pattern1","south",
		"/players/oberon/amber/city/rooms/guardhouse3","west",
	});

	move_object(clone_object("/players/oberon/amber/city/mob/gateguard.c"), this_object());
	move_object(clone_object("/players/oberon/amber/city/mob/gateguard.c"), this_object());
}

init() {
	::init();
	add_action("open_gate","open");
	add_action("close_gate", "close");
	add_action("unlock_gate", "unlock");
	add_action("cmd_north","north");
}

open_gate(arg) {
	if(arg != "gate") return;
	if(gate_open)
		write("The gate is currently open.\n");
	else if(gate_locked)
		write("The gate is locked.\n");
	else {
		write("You open the gate.\n");
		set_gate(1);
		call_other("/players/oberon/amber/city/rooms/southgate", "set_gate", 1);
	}
	return 1;
}

close_gate(arg) {
	if(arg != "gate") return;
	if(!gate_open)
		write("The gate is currently closed.\n");
	else {
		write("You close the gate.\nYou hear a loud click as it closes.\n");
		set_gate(3);
		call_other("/players/oberon/amber/city/rooms/southgate", "set_gate", 3);
	}
	return 1;
}

unlock_gate(arg) {
	if(arg != "gate") return;
	if(!gate_locked)
		write("The gate is already unlocked.\n");
	else {
		/*if(present("southgatekey", this_player())) {*/
			write("You unlock the gate.\n");
			set_gate(2);
			call_other("/players/oberon/amber/city/rooms/southgate", "set_gate", 2);
		/*}*/
		/*else write("You lack the proper key.\n");*/
	}
	return 1;
}

cmd_north() {
	if(!gate_open) {
		write("The city gate is closed.\n");
		return 1;
	}
}

set_gate(value) {
	if(!value) return;
	switch(value) {
		case 1: gate_open=1; gate_locked=0; break;
		case 2: gate_open=0; gate_locked=0; break;
		case 3: gate_open=0; gate_locked=1; break;
		default: break;
	}
	return 1;
}
