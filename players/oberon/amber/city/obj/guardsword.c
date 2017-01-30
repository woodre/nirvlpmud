#include <ansi.h>
#include "/sys/lib.h"
inherit "obj/weapon";

reset(arg) {
	::reset(arg);
	if(arg) return;
	set_name("short sword");
	set_alias("sword");
	set_short("A Short Sword");
	set_long("Provided by the Smith of Amber.\n");
	set_class(10);
	set_weight(1);
	set_value(200+random(1000));
}
