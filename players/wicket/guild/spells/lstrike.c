#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	object attacker;
	int hp, mhp;
	
	attacker = (object)User->query_attack();
	
	if(PO->query_suspend())
	{
		write(YEL+"Aeolos"+NORM+" says: You have lost your rights to do this. You are suspended.\n");
		return 1;
	}
	
	if(PO->query_AIR() < 4)
	{
		write(YEL+"Aeolos"+NORM+" says: You have not learned that yet!\n");
		return 1;
	}
	
	if(User->query_ghost())
	{
		return 0;
	}
	
	if(!attacker)
	{
		write(YEL+"Aeolos"+NORM+" says: You are not fighting anyone! You must be in combat to use this!\n");
		return 1;
	}
	
	if(!present(attacker, environment(User)))
	{
		write(YEL+"Aeolos"+NORM+" says: I'm sorry but there is no"+RED+" "+str+" "+NORM+"here.\n");
		return 1;
	}
	
	if(!attacker->is_npc())
	{
		write(YEL+"Aeolos"+NORM+" says: You can only do that to monsters!\n");
		return 1;
	}
	
	if(User->query_sp() < 25)
	{
		write(YEL+"Aeolos"+NORM+" says: You are too drained to attempt this!\n");
		return 1;
	}
	
	hp = (int)attacker->query_hp();
	mhp = (int)attacker->query_mhp();
	
	if(((hp*10) / mhp) < 1)
	{
		write("You pray to "+YEL+"Aeolos"+NORM+" for assistance.\n");
		write(YEL+"Aeolos"+NORM+" grants you enough energy for a\n");
		write(HIB+"LIGHTNING STRIKE"+NORM+"! "+HIK+"Clouds"+NORM+" swirl around\n");
		write("you as you summon forth a flash of "+HIB+"LIGHTNING"+NORM+" to strike\n");
		write(attacker->query_name()+".\n");
		attacker->heal_self(-hp);
		attacker->hit_player(hp);
		User->add_spell_point(-25);
		return 1;
	}
	
	else
	{
		write(YEL+"Aeolos"+NORM+" says: "+attacker->query_name()+" is still too strong to finish!\n");
		return 1;
	}
	return 1;
}