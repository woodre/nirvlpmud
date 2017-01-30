#include <ansi.h>
#include "/sys/lib.h"
inherit "obj/weapon";

#define MAXCHANCE 50
#define MAXDETOX 10
#define DETOX this_player()->query_prestige_skill("detox")

reset(arg) {
	::reset(arg);
	if(arg) return;
	set_type("sword");
	set_name("sword");
	set_short("An Amber Sword of Detoxing");
	set_long("Provided by the Smith of Amber.\n");
	set_class(5);
	set_weight(1);
	set_value(10000);
	set_save_flag(0);
	set_hit_func(this_object());
}

weapon_hit(attacker) {
	int chance, detox;	
	chance = DETOX;
	if(chance > MAXCHANCE) chance = MAXCHANCE;
	detox = (DETOX > MAXDETOX)? MAXDETOX : DETOX;
	if(random(100) < chance) {
		call_other(this_player(), "add_soaked", -detox);
		call_other(this_player(), "add_stuffed", -detox);
		call_other(this_player(), "add_intoxination", -random(detox));
		/* Note: Intox is set to random(detox), because it's detox numbers are smaller */
		write(
			"You are detoxed by your sword!\n"+
			"DEBUG: chance("+chance+") detox("+detox+")\n"
		);
	}
	return 1;
}
