inherit "obj/armor";

#include <ansi.h>

	reset(arg) {
	set_name("scouter");
	set_alias("helmet");
	set_short(""+HIR+"A Scouter"+NORM+"");
	set_long(
	"This scouter is worn by the members of the Saiyan Royal Guard scouting force.\n"+
	"They use this to measure the strength of their enemy. It has a button on the side to\n"+
	"measure nearby enemies strength, and provides info regarding the enemy.\n");
	set_ac(1);
	set_type("helmet");
	set_weight(1);
	set_value(7500+random(1500));
}