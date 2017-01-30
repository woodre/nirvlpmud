#include <ansi.h>
inherit "/obj/monster";

 reset(arg) {
	::reset(arg);
	if(arg) return;

	set_name("Gate Guard");
	set_alias("guard");
	set_race("human");
	set_short("City Gate Guard");
	set_long("A man guarding the gates of Amber.\n");
	set_gender("male");
	set_level(16);
	set_hp(600 + random(200));
	set_wc(30);
	set_ac(17);
	set_aggressive(0);
	set_al(0);
	add_money(2000+random(1000));

	set_chat_chance(1);
	load_chat("The Gate Guard mumbles something about a lazy guard.\n");

	move_object(clone_object("/players/oberon/amber/city/obj/guardsword"), this_object());
	init_command("wield sword");
	move_object(clone_object("/players/oberon/amber/city/obj/guardshield"), this_object());
	init_command("wear shield");
}

init() {
	::init();
}

heart_beat() {
	::heart_beat();
}
