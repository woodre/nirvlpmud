#include <ansi.h>
inherit "/obj/monster";

int wakechance;

 reset(arg) {
	::reset(arg);
	if(arg) return;

	set_name("Sleeping Guard");
	set_alias("guard");
	set_race("human");
	set_short("A Sleeping Gate Guard");
	set_long(
		"A man guarding the gates of Amber. You get the impression\n"+
		"he should not be sleeping.\n");
	set_gender("male");
	set_level(16);
	set_hp(400 + random(200));
	set_wc(30);
	set_ac(17);
	set_aggressive(0);
	set_al(0);
	add_money(3000+random(1000));
	/*set_killable(0);*/

	set_chat_chance(3);
	load_chat("The sleeping guard snores loudly.\n");

	move_object(clone_object("/players/oberon/amber/city/obj/guardsword"), this_object());
	init_command("wield sword");
	move_object(clone_object("/players/oberon/amber/city/obj/guardshield"), this_object());
	init_command("wear shield");
}

init() {
	::init();
	/*add_action("cmd_wake","wake");*/
	add_action("killcheck","kill");
}

heart_beat() {
	::heart_beat();
}

cmd_wake(arg) {
	if (!arg) return;
	wakechance = random(10);
	if (arg == "guard" && this_object()->query_name() == "Sleeping Guard") {
		if (wakechance <= 2) {
			write("The guard snorts loudly, then suddenly wakes up.\n");
			write("He looks at you, notices you aren't his boss, and\n");
			write("falls back to sleep. Though, something has fallen\n");
			write("from his pocket onto the ground.\n");
			if (!present("southgatekey", environment()))
				move_object(clone_object("/players/oberon/amber/city/obj/southgatekey"), environment());
			return 1;
			/*
			write("The guard snorts loudly, then suddenly wakes up.\n");
			write("The guard says: What?! I fell alseep!\n");
			write("The guard says: Man, the Captains going to kill me if he finds out!\n");
			write("As the guard rushes out, a key falls from his pocket.\n");
			move_object(clone_object("/players/oberon/amber/city/obj/southgatekey"), environment());
			move_object(this_object(), "/room/void");
			init_command("remove shield");
			init_command("unwield sword");
			destruct(this_object());
			return 1;
			*/
		}
		else {
			write("The guard rolls over and falls back asleep.\n");
			return 1;
		}
	}
}

killcheck(arg) {
	if (arg == "guard") {
		if(this_object()->query_name() == "Sleeping Guard") {
			write("The guard suddenly awakes and jumps to his feet!\n");
			set_name("Gate Guard");
			set_short("City Gate Guard");
			set_chat_chance(0);
		}
	}
}
