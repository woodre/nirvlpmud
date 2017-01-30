/*
* Guard Boss - LVL 17
* Spell: shield bash (10% chance for extra random(20) physical dmg)
*/
#include <ansi.h>
inherit "/obj/monster";

 reset(arg) {
	::reset(arg);
	if(arg) return;

	set_name("guard");
	set_alias("boss");
	set_race("human");
	set_short("City Guard Boss");
	set_long("This guard is much bigger and stronger looking than the other guards.\n");
	set_gender("male");
	set_level(17);
	set_hp(1000 + random(200));
	set_wc(30);
	set_ac(20);
	set_aggressive(0);
	set_al(0);
	add_money(4000+random(1000));

	move_object(clone_object("/players/oberon/amber/city/obj/guardsword"), this_object());
	init_command("wield sword");
	move_object(clone_object("/players/oberon/amber/city/obj/guardshield"), this_object());
	init_command("wear shield");

	add_spell("shield_bash",
		"The guard slams you with his shield.\n",
		"The guard slams his shield into #TN#.\n",
		10,random(20),"physical",0);
}

init() {
	::init();
}

heart_beat() {
	::heart_beat();
}
