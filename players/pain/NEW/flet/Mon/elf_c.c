/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
=-=
=-=	elf_c.c
=-=
=-=	An elven child with a random piece of clothing
=-=
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

inherit "/obj/monster";

reset(arg) {
int number;
	::reset(arg);
	set_short("A scared Elven child");
	set_long("An Elven child, scared out of his mind.\n"+
		"The child is only about 3 feet tall, and looks quite fragile.\n");
	set_level(4);
	set_hp(50);
	set_ac(5);
	set_wc(5);
	set_alias("elf child");
	set_name("child");
	number = random(3);
	if(number == 0) {
		move_object(clone_object("/players/pain/NEW/flet/Arm/ec_cloak"),this_object());
	}
	if(number == 1) {
		move_object(clone_object("/players/pain/NEW/flet/Arm/ec_boots"),this_object());
	}
	if(number == 2) {
		move_object(clone_object("/players/pain/NEW/flet/Arm/ec_tunic"),this_object());
	}
	init_command("wear all");
}

init() {
	::init();
}


