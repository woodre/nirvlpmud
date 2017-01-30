#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	object attacker, stun, shadow;
	int randomtrap, length, total;
	
	randomtrap = random(5);
	
	if(User->query_ghost())
	{
		return 1;
	}
	
	if(PO->query_suspend())
	{
		write(GRN+"Aatami"+NORM+" says: You have lost your rights to do this. You are suspended.\n");
		return 1;
	}
	
	if(PO->query_EARTH() < 7)
	{
		write(GRN+"Aatami"+NORM+" says: You do not have the knowledge of this spell yet, young one!\n");
		return 1;
	}
	
	if(User->query_sp() < 20){
		write(GRN+"Aatami"+NORM+" says: You are too drained to attempt this!\n");
		return 1;
	}
	
	if(!str && !User->query_attack()){
		write(GRN+"Aatami"+NORM+" says: I'm sorry but who are you attacking again?\n");
		return 1;
	}
	
	if(!str){
		attacker = (object)User->query_attack(); }
	if(!attacker){
		attacker = present(str, environment(User)); }
	if(!attacker || !present(attacker, environment(User))){
		write(GRN+"Aatami"+NORM+" says: I'm sorry but there is no"+RED+" "+str+" "+NORM+"here.\n");
		return 1;
	}
	
	if(!living(attacker)){
		write(GRN+"Aatami"+NORM+" says: I'm sorry but how are you suppose to attack that?\n");
		return 1;
	}
	
	if(attacker->is_player() && attacker->query_level() > 20){
		write(GRN+"Aatami"+NORM+" says: I'm sorry but casting this on a wizard is forbidden!\n");
		return 1;
	}

 	if(!attacker || !present(attacker, environment(User))){
		write(GRN+"Aatami"+NORM+" says: I'm sorry but there is no "+RED+str+NORM+" here.\n");
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
	
	if(attacker->is_player())
	{
		if(present("no_escape_bitch", attacker)){
			write(GRN+"Aatami"+NORM+" says: Slow down. "+attacker->query_name()+" is already trapped!\n");
			return 1;
		}
	}
	
	if(attacker->is_npc())
	{
		if(attacker->is_imprisoned())
		{
			write(GRN+"Aatami"+NORM+" says: Slow down. "+attacker->query_name()+" is already trapped!\n");
			return 1;
		}
	}
	
	switch(PO->query_eprison()){
		case 666..1000:
		length = 10;
		total = 5;
		break;
		case 333..665:
		length = 7;
		total = 3;
		break;
		default:
		length = 5;
		total = 1;
		break;
	}
	
	if(attacker->is_player())
	{
		stun = clone_object("/players/wicket/guild/objs/earthtrap.c");
		move_object(stun, attacker);
		stun->set_traplength(total);
		write(HIY+"\nLarge stones erupt from the Earth and surround\n");
		write(HIY+"themselves around "+attacker->query_name()+"'s feet!\n"+NORM);
	}
	
	if(attacker->is_npc())
	{
		shadow = clone_object("/players/wicket/guild/objs/prison.c");
		shadow->set_victim(attacker);
		shadow->set_time(length);
		write(HIY+"\nLarge stones erupt from the Earth and surround\n");
		write(HIY+"themselves around "+attacker->query_name()+"'s feet!\n"+NORM);
	}
	
	switch(randomtrap){
		case 0..1:
			if(PO->query_eprison() < 495){
				PO->add_eprison(1);
			}
		break;
		case 3..4:
			if(PO->query_eprison() < 495){
				PO->add_eprison(2);
			}
		break;
		default:
			if(PO->query_eprison() < 495){
				PO->add_eprison(3);
			}
		break;
	}
	
	User->add_spell_point(-20);
	
	return 1;
}

























/*#include <ansi.h>
#include "/players/wicket/guild/defs.h"
status main(string str, object PO, object User)
{
	int randomtrap, length;
	object attacker, stun;

	randomtrap = random(5);
	if(User->query_ghost()){
		return 1;
	}
	
	if(PO->query_suspend())
	{
		write(GRN+"Aatami"+NORM+" says: You have lost your rights to do this. You are suspended.\n");
		return 1;
	}
	
	if(PO->query_EARTH() < 7){
		write(GRN+"Aatami"+NORM+" says: You do not have the knowledge of this spell yet, young one!\n");
		return 1;
	}
	
	if(User->query_sp() < 20){
		write(GRN+"Aatami"+NORM+" says: You are too drained to attempt this!\n");
		return 1;
	}
	
	if(!str){
		attacker = (object)User->query_attack(); }
	if(!attacker){
		attacker = present(str, environment(User)); }
	if(!attacker || !present(attacker, environment(User))){
		write(GRN+"Aatami"+NORM+" says: I'm sorry but there is no"+RED+" "+str+" "+NORM+"here.\n");
		return 1;
	}
	
	if(attacker->is_player() && attacker->query_level() > 20){
		write(GRN+"Aatami"+NORM+" says: I'm sorry but casting this on a wizard is forbidden!\n");
		return 1;
	}

 	if(!attacker || !present(attacker, environment(User))){
		write(GRN+"Aatami"+NORM+" says: I'm sorry but there is no "+RED+str+NORM+" here.\n");
		return 1;
	}
	
	if(!living(attacker)){
		write(GRN+"Aatami"+NORM+" says: I'm sorry but how are you suppose to attack that?\n");
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
	
	if(present("no_escape_bitch", attacker)){
		write(GRN+"Aatami"+NORM+" says: Slow down. "+attacker->query_name()+" is already trapped!\n");
		return 1;
	}
	
	switch(PO->query_eprison()){
		case 666..1000:
		length = 10;
		break;
		case 333..665:
		length = 5;
		break;
		default:
		length = 3;
		break;
	}

	stun = clone_object("/players/wicket/guild/objs/earthtrap.c");
	move_object(stun, attacker);
	stun->set_traplength(length);
	write(HIY+"\nLarge stones erupt from the Earth and surround\n");
	write(HIY+"themselves around "+attacker->query_name()+"'s feet!\n"+NORM);
	User->add_spell_point(-20);
	
	switch(randomtrap){
		case 0..1:
			if(PO->query_eprison() < 495){
				PO->add_eprison(1);
			}
		break;
		case 3..4:
			if(PO->query_eprison() < 495){
				PO->add_eprison(2);
			}
		break;
		default:
			if(PO->query_eprison() < 495){
				PO->add_eprison(3);
			}
		break;
	}
	return 1;
}*/