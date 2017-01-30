inherit "/obj/generic_heal.c";
#include <ansi.h>

void reset(int arg)
{
	::reset(arg);
	if(arg) return;

	set_name("tube");
	add_alias("red tube");
	set_long(
"This is a small tube that one would\n"+
"normally use in Chemisty class.\n"+
"Maybe you can 'drink tube' to gain\n"+
"some health back.\n");
	set_type("uses");
	set_type_single("use");
	set_msg("You uncork the tube and take a quick sip\n"+
			"You feel somewhat better.\n");
	set_msg2(" uncorks the flask and takes a quick sip.\n");
	set_empty_msg("");
	add_cmd("drink");
	set_heal(100,0);
	set_charges(5);
	set_soak(12);
	set_stuff(12);
	set_value(1200);
	set_msg_soaked("You catch a whiff of the chemicals and decide to not drink any\n");
	set_msg_stuffed("You catch a whiff of the chemicals and decide to not drink any\n");
}

query_save_flag(){ return 1; }

short()
{
	return "A "+RED+"Red "+NORM+"tube ("+charges+")";
}

int use_charge()
{
	if(charges) charges--;
	if(charges <= 0) destruct(this_object());
	return charges;
}
