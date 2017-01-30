inherit "obj/weapon";
#include "/obj/ansi.h"
#include "/players/mizan/mines/definitions.h"

reset(arg) 
{
	::reset(arg);
        if(!arg)
	{
                set_name("sword");
		set_class(18);
		set_value(10000);
		set_weight(2);
                set_alias("Sword");
		set_short(HIY + "Yo Mama's Sword" + NORM);
set_long(
"  This is a really nasty looking thing, glowing with the power of many, many\n"+
"  volts. Be careful with the way you wield that thing... you could really\n"+
"  toast someone's eyeballs!\n");
		set_hit_func(this_object());
	}
}


weapon_hit(attacker)
{
	string insult, attacker_name;

	insult = MAMASNAPS_DM->query_snap();

	if(attacker && attacker->is_living())
	{
		attacker_name = attacker->query_name();

		if(random(100) < 24)  
		{
			write("Your sword sings...\" " + insult + "\"\n");
			say((this_player()->query_name()) + "'s sword says to " + attacker_name + ": \"" + insult + "\n");
		return 3;
		}
	}
}
