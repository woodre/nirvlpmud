#include <ansi.h>
#include "/sys/lib.h"
inherit "obj/weapon";

#define MAXCHANCE 20
#define HPHEAL this_player()->query_prestige_skill("reghp")
#define SPHEAL this_player()->query_prestige_skill("regsp")

reset(arg) {
	::reset(arg);
	if(arg) return;
	set_type("sword");
	set_name("sword");
	set_short("An Amber Sword of Healing");
	set_long("Provided by the Smith of Amber.\n");
	set_class(5);
	set_weight(1);
	set_value(10000);
	set_save_flag(0);
	set_hit_func(this_object());
}

weapon_hit(attacker) {
	int chance, heal;
	chance = HPHEAL;
	if(chance > MAXCHANCE) chance = MAXCHANCE;
	heal = random( (HPHEAL > chance)? chance+((HPHEAL-chance) /5) : chance );
	if(random(100) < chance) {
		call_other(this_player(), "add_hit_point", heal);
		write("Your health is healed by your sword!\n");
	}
	chance = SPHEAL;
	if(chance > MAXCHANCE) chance = MAXCHANCE;
	heal = random( (SPHEAL > chance)? chance+((SPHEAL-chance) /5) : chance );
	if(random(100) < chance) {
		call_other(this_player(), "add_spell_point", heal);
		write("Your magic is healed by your sword!\n");
	}
	return 1;
}
