#include <ansi.h>
#include "/sys/lib.h"
inherit "obj/generic_heal";

reset(arg) {
	::reset(arg);
	if(arg) return;
	set_name("potion");
	set_short("A potion of healing");
	set_long("Provided by the FoodSmith of Amber.\n");
	
	set_type("drinks");
	add_cmd("drink");
	msg = "You drink from the potion.\n"; /* Ex: You chug a quart of beer!  You rip off a haunch of beef. etc. */
	msg2 = " drinks from a potion.\n"; /* "chugs a quart of beer!" "rips off a haunch of beef." */
	
	set_charges(3);
	set_heal(50, 50);
	set_intox(1);
	set_stuff(5);
	set_soak(5);
	set_value(2250);
}
