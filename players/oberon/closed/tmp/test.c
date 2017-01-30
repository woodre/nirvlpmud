#include <ansi.h>
#include "/sys/lib.h"
inherit "obj/weapon";

reset(arg) {
	::reset(arg);
	if(arg) return;
	set_type("sword");
	set_name("sword");
	set_short("An Amber Sword");
	set_long("Provided by the Smith of Amber.\n");
	set_class(20);
	set_weight(1);
	set_value(0);
	set_save_flag(0);
	set_hit_func(this_object());
}

weapon_hit(attacker) {
	return 9999;
}
