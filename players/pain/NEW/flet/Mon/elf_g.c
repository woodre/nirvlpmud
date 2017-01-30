/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
=-=
=-=	elf_g.c
=-=
=-=	A basic elven guard
=-=
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

inherit "obj/monster";
#include "/players/pain/color.h"

reset(arg) {
int number;
	::reset(arg);
	set_short(BOLD+GREEN+"Elven Guard"+END+" \(elven protector\)");
	set_long("The "+BOLD+GREEN+"Elven Guard"+END+
		" is a protector of the\n"+
		"Vale and flet. He is a fearsome looking elf, with a wise\n"+
		"contenance and watchful eyes. You would do well to not\n"+
		"arouse his anger.\n");
	set_level(15);
	set_hp(350+random(100));
	set_race("elf");
	set_name("elf");
	set_alias("guard");
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
}

