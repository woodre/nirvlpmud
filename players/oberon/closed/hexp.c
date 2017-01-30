#include <ansi.h>
inherit "/obj/monster";

 reset(arg) {
	::reset(arg);
	if(arg) return;

	set_name("lunatic");
	set_race("human");
	set_short("A Crazed Lunatic");
	set_long("Truly a loon. He isn't even worth killing.\n");
	set_gender("male");
	set_level(200);
	set_hp(1);
	set_wc(5000);
	set_ac(5000);
	set_aggressive(0);
	set_al(0);
	/*
	set_ep(1000000);
	experience = 1000000;
	*/
	set_chat_chance(1);
	load_chat("The lunatic stares at you with his crazy eyes.\n");
}

init() {
	::init();
	/*
	set_ep(1000000);
	experience = 1000000;
	*/
}

heart_beat() {
	::heart_beat();
}
