#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	object attacker, shadow;
	int air, earth, fire, water, total;
	
	air = (int)PO->query_AIR();
	earth = (int)PO->query_EARTH();
	fire = (int)PO->query_FIRE();
	water = (int)PO->query_WATER();
	
	total = air + earth + fire + water;
	
	if(PO->query_suspend())
	{
		write(CYN+"Glyndwr"+NORM+" says: You have lost your rights to do this. You are suspended.\n");
		return 1;
	}
	
	if(PO->query_WATER() < 3)
	{
		write(CYN+"Glyndwr"+NORM+" says: You do not have the knowledge of that yet.\n");
		return 1;
	}
		
	if(User->query_ghost()){
		return 1;
	}
	
	if(User->query_sp() < 40)
	{
		write(CYN+"Glyndwr"+NORM+" says: You do not have the magical energies needed to cast that!\n");
		return 1;
	}
	
	if(PO->query_isprayCD())
	{
		write(CYN+"Glyndwr"+NORM+" says: You cannot use that ability again so soon!\n");
		return 1;
	}
	
	if(!str && !User->query_attack()){
		write(CYN+"Glyndwr"+NORM+" says: I'm sorry but who are you attacking again?\n");
		return 1;
	}
	
	if(!str){
		attacker = (object)User->query_attack(); }
	if(!attacker){
		attacker = present(str, environment(User)); }
	if(!attacker || !present(attacker, environment(User))){
		write(CYN+"Glyndwr"+NORM+" says: I'm sorry but there is no "+RED+str+NORM+" here.\n");
		return 1;
	}
	if(!living(attacker)){
		write(CYN+"Glyndwr"+NORM+" says: I'm sorry but that is not living.\n");
		return 1;
	}
	
	if(attacker->query_stunned())
	{
		write(CYN+"Glyndwr"+NORM+" says: I cannot help you do that while "+attacker->query_name()+" is stunned.\n");
		return 1;
	}
	
	if(attacker->is_sprayed())
	{
		write(CYN+"Glyndwr"+NORM+" says: That is already encased in ice!\n");
		return 1;
	}
	
	if(attacker->is_player())
	{
		write(CYN+"Glyndwr"+NORM+" says: You cannot use that on other players!\n");
		return 1;
	}
	
	shadow = clone_object("/players/wicket/guild/objs/shadow.c");
	shadow->set_victim(attacker);
	shadow->set_time(total);
	write(BOLD+"You focus the powers of "+NORM+CYN+"Glyndwr"+NORM+BOLD+" and encase "+attacker->query_name()+" with an"+CYN+" icy spray"+NORM+BOLD+"!\n"+NORM);
	say(BOLD+User->query_name()+" focuses the powers of "+NORM+CYN+"Glyndwr"+NORM+BOLD+" and encases "+attacker->query_name()+" with an"+CYN+" icy spray"+NORM+BOLD+"!\n"+NORM);
	User->add_spell_point(-40);
	PO->start_isprayCD();		
	return 1;
}
