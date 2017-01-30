#include <ansi.h>
#include "/sys/lib.h"
inherit "obj/treasure";

reset(arg) {
	::reset(arg);
	if(arg) return;
	set_name("southgatekey");
	set_alias("key");
	set_short("South Gate Key");
	set_long("Provided by the Smith of Amber.\n");
	set_weight(1);
}
