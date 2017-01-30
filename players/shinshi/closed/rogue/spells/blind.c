#include "../defs.h"

status main(string str, object PO, object User)
{
	int randomblind;
	object blind, attacker, prevent;
	
	randomblind = random(5);
	
	if(User->query_ghost()){
		return 1;
	}
	
	if(User->query_extra_level() < 27){
		write("You cannot use that ability yet.\n");
		return 1;
	}
	
	if(present("shinshi_no_blind", User)){
		write("You cannot use that ability so soon!\n");
		return 1;
	}
	
	if(User->query_sp() < 60){
		write("You don't have the energy to do that.\n");
		return 1;
	}
	
	if(User->query_spell_dam()){
		write("You can't attack again so soon!\n");
		return 1;
	}
	
	if(!str && !User->query_attack()){
		write("What would you like to blind?\n");
		return 1;
	}
	
	if(!str){
		attacker = (object)User->query_attack(); }
	if(!attacker){
		attacker = present(str, environment(User)); }
	if(!attacker || !present(attacker, environment(User))){
		write("You don't see "+str+" here.\n");
		return 1;
	}
	if(!living(attacker)){
		write("That isn't alive to blind.\n");
		return 1;
	}
	
	if(!attacker->is_npc() && attacker->query_level() > 19){
		write("You cannot attack a wizard!\n");
		return 1;
	}
	
	blind = clone_object(OBJPATH+"blinded.c");
	move_object(blind, attacker);
	blind->start_it();
	write("You throw blinding powder in "+attacker->query_name()+"'s face!\n");
	tell_object(attacker, User->query_name()+" throws blinding powder in your face!\n");
	User->add_spell_point(-60);
	
	switch(randomblind){
		case 0..1:
			if(PO->query_blind() < 1000){
				PO->add_blind(10);
			}
		break;
		case 3..4:
			if(PO->query_blind() < 1000){
				PO->add_blind(20);
			}
		break;
		default:
			if(PO->query_blind() < 1000){
				PO->add_blind(30);
			}
		break;
	}
	
	prevent = clone_object(OBJPATH+"blindstop.c");
	move_object(prevent, User);
	prevent->start_it();
	return 1;
	
}