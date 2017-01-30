#include <ansi.h>
#include "/sys/lib.h"
inherit "obj/armor";

object amber_rop;
int rlevel;

reset(arg) {
	::reset(arg);
	if(arg) return;
	rlevel = this_player()->query_prestige_skill("ac");
	if(rlevel < 1 && this_player()->query_prestige_level() > 0) rlevel = 1;
	
	set_name("rop");
	set_alias("ring");
	set_short("Ring of Protection +"+rlevel+"");
	set_long("Provided by the Smith of Amber.\n");
	set_type("ring");
	set_weight(1);
	set_value(0);
	set_save_flag(0);
	set_ac(0);
}

init() {
	::init();
	amber_rop = this_object();
	call_out("pres_check", 5, amber_rop);
}

pres_check(object rop) {
	object pobj;
	pobj = environment(rop);
	rop->set_ac(rlevel);
}
