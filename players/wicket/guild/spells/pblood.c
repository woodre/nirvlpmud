#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	if(PO->query_suspend())
	{
		write(RED+"Adroushan"+NORM+" growls, \"You lost your ability to do that, fool.\"\n");
		return 1;
	}
	
	if(PO->query_FIRE() < 3)
	{
		write(RED+"Adroushan"+NORM+" growls, \"You do not have the knowledge of that spell yet.\"\n");
		return 1;
	}
	
	if(PO->query_pbloodCD())
	{
		write(RED+"Adroushan"+NORM+" growls, \"That ability is still on cooldown.\"\n");
		return 1;
	}
	
	if(User->query_hp() < 10)
	{
		write(RED+"Adroushan"+NORM+" growls, \"You don't have the "+HIR+"blood"+NORM+" to sacrifice!\"\n");
		return 1;
	}
	
	if(User->query_sp() < 20)
	{
		write(RED+"Adroushan"+NORM+" growls, \"You don't have the magical energies to do that!\"\n");
		return 1;
	}
	
	User->eat_food(-10);
	User->drink_soft(-10);
	User->add_spell_point(-20);
	User->add_hit_point(-10);
	PO->start_pbloodCD();
	write("You pray to "+RED+"Adroushan"+NORM+".\n");
	write("		You feel a sudden burning sensation within your "+HIR+"blood stream"+NORM+".\n");
	write("			Your blood begins to "+HIK+"BOIL"+NORM+".\n");
	write("\n");
	write("The toxins in your "+HIR+"blood stream"+NORM+" begins to burn up!\n");
	write("\n");
	write("The burning sensation dies down and you feel slightly better.\n");
	say(User->query_name()+" prays to "+RED+"Adroushan"+NORM+".\n");
	say("		"+User->query_name()+" screams out in agony.\n");
	return 1;
}
