#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	object fire, attacker;
	int damage, miss, chance;
	
	fire = clone_object("/players/wicket/guild/objs/fire.c");
	miss = random(11);
	chance = random(99);
	
	if(PO->query_suspend())
	{
		write(RED+"Adroushan"+NORM+" growls: You have lost your rights to do this. You are suspended.\n");
		return 1;
	}
	
	if(PO->query_FIRE() < 4)
	{
		write(RED+"Adroushan"+NORM+" says: You do not have the knowledge of this spell yet, young one!\n");
		return 1;
	}
		
	if(User->query_ghost()){
		return 1;
	}
	
	if(User->query_spell_dam()){
		write(RED+"Adroushan"+NORM+" growls: Slow down! You cannot attack again just yet!\n");
		return 1;
	}
	
	if(!str && !User->query_attack()){
		write(RED+"Adroushan"+NORM+" growls: Stupid "+User->query_race()+"! Who are you trying to attack?\n");
		return 1;
	}
	
	if(!str){
		attacker = (object)User->query_attack(); }
	if(!attacker){
		attacker = present(str, environment(User)); }
	if(!attacker || !present(attacker, environment(User))){
		write(RED+"Adroushan"+NORM+" growls: Stupid "+User->query_race()+"! "+str+" is not here!\n");
		return 1;
	}
	if(!living(attacker)){
		write(RED+"Adroushan"+NORM+" laughs at you and says: Only a puny "+User->query_race()+" would try to attack something that isn't alive!\n");
		return 1;
	}
	
	if(attacker->is_player() && attacker->query_level() > 20)
	{
		write(RED+"Adroushan"+NORM+" laughs at you for attempting to kill a wizard.\n");
		return 1;
	}		
	
	if(present("engulf_damage", attacker))
	{
		write(RED+"Adroushan"+NORM+" growls: "+attacker->query_name()+" has already been engulfed in flames once.\n");
		return 1;
	}
	
	if(!User->query_fight_area())
	{	
		if(!User->query_pl_k() && attacker->is_player())
		{
			write(RED+"Adroushan"+NORM+" growls: Casting this on another player means you need your PK flag set.\n");
			return 1;
		}
		
		if(User->query_pl_k() && (attacker->is_player() && !attacker->query_pl_k()))
		{
			write(RED+"Adroushan"+NORM+" growls: That player does not PK flag set.\n");
			return 1;
		}
		
		if(!User->query_pl_k() && (attacker->is_player() && !attacker->query_pl_k()))
		{
			write(RED+"Adroushan"+NORM+" growls: Neither of you have your PK flag set.\n");
			return 1;
		}
	}
	
	if(User->query_sp() < 60)
	{
		write(RED+"Adroushan"+NORM+" growls: You are too drained to attempt this!!.\n");
		return 1;
	}
	
	if(PO->query_firebond())
	{
		damage *= 4;
		damage /= 3;
	}
	
	if(PO->query_airshroud())
	{
		if(chance < 15){
			write(YEL+"\n\nAeolos "+NORM+BOLD+"says: I have blessed you with another attack. Strike now!\n\n"+NORM);
			User->set_spell_dam(0);
		}
	}
	
	if(miss < 3)
	{
		write(BOLD+"Your "+RED+"Engulf "+NORM+"spell fails and misses!\n"+NORM);
		return 1;
	}
	
	write(BOLD+"You focus the powers of "+NORM+RED+"Adroushan"+NORM+BOLD+" and engulf "+attacker->query_name()+" in "+HIR+"flames"+NORM+BOLD+"!\n"+NORM);
	tell_object(attacker, User->query_name()+BOLD+" focuses the powers of "+NORM+RED+"Adroushan"+NORM+BOLD+" and engulfs you in "+HIR+"flames"+NORM+BOLD+"!\n"+NORM);
	tell_object(environment(attacker), User->query_name()+" "+BOLD+"focuses the powers of "+NORM+RED+"Adroushan"+NORM+BOLD+" and engulfs "+attacker->query_name()+" in "+HIR+"flames"+NORM+BOLD+"!\n"+NORM);
	User->add_spell_point(-60);
	move_object(fire, attacker);
	fire->start_it();
	User->attack_object(attacker);
	
	return 1;
}
