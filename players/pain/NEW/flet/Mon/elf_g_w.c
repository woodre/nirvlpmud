/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
=-=
=-=	elf_g_W.c
=-=
=-=	A basic elven guard
=-=
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

inherit "/obj/monster";
#include "/players/pain/color.h"

reset(arg) {
int number;
	::reset(arg);
	set_short("A wandering "+BOLD+GREEN+"Elven Guard"+END+" \(elven guardian\)");
	set_long("The "+BOLD+GREEN+"Elven Guard"+END+
		"is a protector of the\n"+
		"Vale and flet. He is a fearsome looking elf, with a wise\n"+
		"contenance and watchful eyes. You would do well to not\n"+
		"arouse his anger.\n");
	set_level(17);
	set_race("elf");
	set_hp(350+random(175));
	set_aggressive(1);
	load_a_chat("Long live the Elven Kings!\n");
	number = random(3);
	if(number == 0) {
		move_object(clone_object("/players/pain/NEW/flet/Wep/eg_scimitar"),this_object());
		init_command("wield scimitar");
	}
	if(number == 1) {
		move_object(clone_object("/players/pain/NEW/flet/Wep/eg_bow"),this_object());
		init_command("wield bow");
	}
	if(number == 2) {
		move_object(clone_object("/players/pain/NEW/flet/Arm/eg_cloak"),this_object());
		init_command("wear cloak");
	}
	set_wc(17);
	set_ac(9);
	call_out("wander",10);
}

wander() {
int number;

	number = random(10);
	if(number == 0) { command("north",this_object()); }
	if(number == 1) { command("east",this_object()); }
	if(number == 2) { command("south",this_object()); }
	if(number == 3) { command("west",this_object()); }
	if(number == 4) { command("northeast",this_object()); }
	if(number == 5) { command("southeast",this_object()); }
	if(number == 6) { command("southwest",this_object()); }
	if(number == 7) { command("northwest",this_object()); }
	if(number == 8) { command("up",this_object()); }
	if(number == 9) { command("down",this_object()); }
	call_out("wander",30);
	return 1;
}


