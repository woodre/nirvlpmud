#include <ansi.h>
#include "/sys/lib.h"
inherit "/room/room";

int gate_open, gate_locked;

reset(arg) {
	::reset(arg);
	if(arg) return;
	set_gate(3);
	set_light(1);
	short_desc = "Inside the South Gate of Amber";
	long_desc =
		"Finally inside the City of Amber, the large entrance gate is to the\n"+
		"south. To the east and west lay a road that wraps around the southern\n"+
		"side of the city. To the north appears to be a shop selling information\n"+
		"about the city of Amber. You can hear the bustle of people throughout\n"+
		"the streets.\n";
	items = ({
		"gate","A large gate to the south appears large enough for\n"+
			"an army to easily march through",
	});
	dest_dir = ({
		"/players/oberon/amber/city/rooms/shop_info","north",
		"/players/oberon/amber/city/rooms/southwall3","east",
		"/players/oberon/amber/city/rooms/outside","south",
		"/players/oberon/amber/city/rooms/southwall2","west",
	});

	if(random(2) == 0)
		move_object(clone_object("/players/oberon/amber/city/mob/guardboss.c"), this_object());
	move_object(clone_object("/players/oberon/amber/city/mob/gateguard.c"), this_object());
	move_object(clone_object("/players/oberon/amber/city/mob/gateguard.c"), this_object());
}

init() {
	::init();
	add_action("open_gate","open");
	add_action("close_gate", "close");
	add_action("unlock_gate", "unlock");
	add_action("cmd_south","south");
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
		call_other("/players/oberon/amber/city/rooms/outside", "set_gate", 1);
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
		call_other("/players/oberon/amber/city/rooms/outside", "set_gate", 3);
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
			call_other("/players/oberon/amber/city/rooms/outside", "set_gate", 2);
		/*}*/
		/*else write("You lack the proper key.\n");*/
	}
	return 1;
}

cmd_south() {
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
