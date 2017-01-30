#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	object attacker;
	
	if(PO->query_suspend())
	{
		write(RED+"Adroushan"+NORM+" says: You have lost your rights to do this. You are suspended.\n");
		return 1;
	}
		
	if(User->query_ghost()){
		return 1;
	}
	
	if(PO->query_FIRE() < 7)
	{
		write(RED+"Adroushan"+NORM+" growls: You haven't learned that yet!\n");
		return 1;
	}
	
	if(User->query_sp() < 40)
	{
		write(RED+"Adroushan"+NORM+" growls: You do not have the magical energies needed, "+User->query_race()+"!\n");
		return 1;
	}
	
	if(PO->query_pyroblastCD())
	{
		write(RED+"Adroushan"+NORM+" says: You cannot do that again so soon, "+User->query_race()+".\n");
		return 1;
	}
	
	if(PO->query_pyroblast())
	{
		write(RED+"Adroushan"+NORM+" says: Are you stupid, "+User->query_race()+"??? You're already casting "+HIR+"Pyroblast"+NORM+"!\n");
		return 1;
	}
	
	if(User->query_spell_dam()){
		write(RED+"Adroushan"+NORM+" says: Slow down. You cannot attack again just yet!\n");
		return 1;
	}
	
	attacker = (object)User->query_attack();
	
	if(!attacker)
	{
		write(RED+"Adroushan"+NORM+" says: Slow down. You must engage your opponent in combat first!.\n");
		return 1;
	}
	
	write(BOLD+"You focus your energy drawing from the strength of "+NORM+RED+"Adroushan"+NORM+BOLD+"....\nYou Start forming a "+HIR+"MASSIVE PYROBLAST"+NORM+BOLD+"!\n"+NORM);
	tell_object(environment(User), User->query_name()+" "+BOLD+" focuses their energy drawing strength from"+NORM+RED+" Adroushan"+NORM+BOLD+"....\nThey Beging Forming a "+HIR+"MASSIVE PYROBLAST"+NORM+BOLD+"!\n"+NORM);
	User->add_spell_point(-55);
	PO->set_pyroblast(1);
	PO->set_pyro(0);
	PO->start_pyroblastCD();
	return 1;
}