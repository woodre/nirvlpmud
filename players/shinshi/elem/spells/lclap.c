#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	object stunobj, attacker;
	
	stunobj = clone_object("/players/wicket/guild/objs/clapobj.c");
	
	if(PO->query_suspend())
	{
		write(YEL+"Aeolos"+NORM+" says: You have lost your rights to do this. You are suspended.\n");
		return 1;
	}
	
	if(User->query_ghost()){
		return 1;
	}
	
	if(PO->query_AIR() < 3)
	{
		write(YEL+"Aeolos"+NORM+" says: You do not have the knowledge of this spell yet, young one!\n");
		return 1;
	}
	
	if(User->query_spell_dam()){
		write(YEL+"Aeolos"+NORM+" says: You are not yet ready to do this again!\n");
		return 1;
	}
	
	if(!str && !User->query_attack()){
		write(YEL+"Aeolos"+NORM+" says: I'm sorry but who are you attacking?n");
		return 1;
	}
	
	if(!str){
		attacker = (object)User->query_attack(); }
	if(!attacker){
		attacker = present(str, environment(User)); }
	if(!attacker || !present(attacker, environment(User))){
		write(YEL+"Aeolos"+NORM+" says: I'm sorry but there is no"+RED+" "+str+" "+NORM+"here.\n");
		return 1;
	}
	if(!living(attacker)){
		write(YEL+"Aeolos"+NORM+" says: How are you suppose to attack that?\n");
		return 1;
	}
	
	if(attacker->is_player())
	{
		write(YEL+"Aeolos"+NORM+" says: I'm sorry but casting this on another player is forbidden!.\n");
		return 1;
	}
	
		
	if(User->query_sp() < 30){
		write(YEL+"Aeolos"+NORM+" says: You are too drained to attempt this!\n");
		return 1;
	}
	
	if(present("other_stuff_bitch_tits", attacker))
	{
		write(YEL+"Aeolos"+NORM+" says: "+attacker->query_name()+" is already stunned!\n");
		return 1;
	}
	
	write(BOLD+"\nYou kneel and pray to "+NORM+YEL+"Aeolos"+NORM+BOLD+".\n"+NORM+YEL+"    Aeolos"+NORM+BOLD+"' "+HIW+"winds"+NORM+BOLD+" lift you high into the "+CYN+"sky"+NORM+BOLD+".\n        You find your target and begin to fly towards\n            "            +attacker->query_objective()+" at high speed. You near "+attacker->query_name()+" and\n"+HIR+"		S - L - A - M	"+NORM+BOLD+"\n                     into the ground, stunning "+attacker->query_objective()+".\n"+NORM);
	tell_object(attacker, BOLD+"			"+User->query_name()+" prays to "+NORM+YEL+"Aeolos"+NORM+BOLD+".\n\n\n"+OFF+User->query_name()+" jumps high into the sky and "+HIR+"SLAMS"+NORM+BOLD+" into the ground, stunning you."+NORM+"\n");
	move_object(stunobj, attacker);
	stunobj->start_it();
	User->add_spell_point(-30);	
	return 1;
}
