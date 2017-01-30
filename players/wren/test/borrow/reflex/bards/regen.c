#include "/players/reflex/lib/include/ansi.h"

inherit "obj/treasure";
/* <change by="Erasmios" date="2001-07-04"> */
int max;
/* </change> */

extra_look(){
	return environment()->query_name()+"'s body is "+HIY+"regenerating"+NORM+" rapidly";
}

reset(arg)
{
	if (arg)
		return;
	set_id("regen");
	set_weight(0);
	set_value(0);
	call_out("regen", 2);
}

regen()
{
	/* <change by="Erasmios" date="2001-07-04"> */
	int first, second;
	int health;

/* environment() check added by Beck 3/25/2002/ */
if(environment()){
	if (!max) max = environment()->query_mhp();
	environment()->add_hit_point(2);
	max -= 3;

	first = environment()->query_hp();
	second = environment()->query_mhp();
}

	if (first == second || max <= 0) {
		endgame();
	} else {
		call_out("regen", 2);
	}
	/* </change> */
}

endgame()
{
	remove_call_out("regen");
	say("You stop "+HIY+"regenerating"+NORM+".\n");
	destruct(this_object());
	return 1;
}

drop()
{
	return 1;
}

get()
{
	return 1;
}

can_put_and_get()
{
	return 0;
}
