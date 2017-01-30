inherit "/obj/generic_heal.c";
#include <ansi.h>

void reset(int arg)
{
	::reset(arg);
	if(arg) return;

	set_name("tube");
	add_alias("chem tube");
	set_long(
"This is a larger tube that one would\n"+
"normally use in Chemistry class\n"+
"Maybe you can 'drink tube' to gain\n"+
"your health back. \n");
	set_type("uses");
	set_type_single("use");
	set_msg("You uncork the tube and take a quick sip\n"+
			"You feel completely better.\n");
	set_msg2(" uncorks the tube and takes a quick sip.\n");
	set_empty_msg("You crush the empty tube with your newly found strength.\n");
	add_cmd("drink");
        set_heal(10000,10000);
        set_soak(-1000);
        set_stuff(-1000);
        set_intox(-1000);
	set_charges(3);
	set_value(0);
}

query_save_flag(){ return 1; }

short()
{
	return "A "+HIK+"bubbling "+NORM+"tube ("+charges+")";
}

int use_charge()
{
	if(charges) charges--;
	if(charges <= 0) destruct(this_object());
	write("You crush the tube with your newly found strength.\n");
	return charges;
}
