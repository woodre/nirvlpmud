#include <ansi.h>
#include "/sys/lib.h"
inherit "obj/armor";

reset(arg) {
	::reset(arg);
	if(arg) return;
	set_name("rop");
	set_alias("ring");
	set_short("Ring of Protection");
	set_long("Provided by the Smith of Amber.\n");
	set_type("ring");
	set_weight(1);
	set_value(80000);
}

init() {
	::init();
	add_action("pres_check","wear");
}

pres_check() {
	int rlevel, rnum;
	int i, dvalues;
	string dtypes;
	rlevel = this_player()->query_prestige_skill("ac");
	dtypes = ({
		"physical",
		"magical",
		"other|dark",
		"other|light",
		"other|water",
		"other|fire",
		"other|wind",
		"other|earth",
		"other|ice",
		"other|electric",
		"other|laser",
		"other|evil",
		"other|good",
		"other|poison",
		"other|sonic",
		"other|mental"
	});
	/* Reset Params first! */
	dvalues = ({0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0});
	clear_params();
	/* Set Params */
	for(i=0;i<rlevel;i++) {
		rnum = random(sizeof(dvalues));
		dvalues[rnum] += 1;
	}
	for(i=0;i<sizeof(dvalues);i++) {
		if(dvalues[i] > 0)
			set_params(dtypes[i],0,dvalues[i],0);
	}
}
