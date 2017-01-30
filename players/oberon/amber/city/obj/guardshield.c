#include <ansi.h>
#include "/sys/lib.h"
inherit "obj/armor";

reset(arg) {
	::reset(arg);
	if(arg) return;
	set_name("small shield");
	set_alias("shield");
	set_short("A Small Shield");
	set_long("Provided by the Smith of Amber.\n");
	set_type("shield");
	set_ac(1);
	set_weight(1);
	set_value(200+random(1000));
}
