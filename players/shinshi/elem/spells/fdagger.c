#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	int damage, cost, randagger, chance;
	object attacker;
	string msg1, msg2, msg3;
	
	randagger = random(5);
	chance = random(99);
	
	if(PO->query_suspend())
	{
		write(RED+"Adroushan "+NORM+"says: You have lost your rights to do this. You are suspended.\n");
		return 1;
	}
	
	if(PO->query_FIRE() < 1)
	{
		write(RED+"Adroushan"+NORM+" growls: You don't know that spell yet, "+User->query_race()+".\n");
		return 1;
	}
	
	if(User->query_ghost()){
		return 1;
	}
	
	if(User->query_spell_dam()){
		write(RED+"Adroushan "+NORM+"says: Slow down. You cannot attack again just yet!\n");
		return 1;
	}
	
	if(!str && !User->query_attack()){
		write(RED+"Adroushan "+NORM+"says: I'm sorry but who are you attacking again?\n");
		return 1;
	}
	
	if(!str){
		attacker = (object)User->query_attack(); }
	if(!attacker){
		attacker = present(str, environment(User)); }
	if(!attacker || !present(attacker, environment(User))){
		write(RED+"Adroushan "+NORM+"says: I'm sorry but there is no"+RED+" "+str+" "+NORM+"here.\n");
		return 1;
	}
	if(!living(attacker)){
		write(RED+"Adroushan "+NORM+"says: I'm sorry but how are you suppose to attack that?\n");
		return 1;
	}
	
	switch(PO->query_fdagger()){
		case 400..500:
		damage = 35 + random(20);
		cost = 50;
		break;
		case 300..399:
		damage = 25 + random(15);
		cost = 45;
		break;
		case 200..299:
		damage = 20 + random(10);
		cost = 40;
		break;
		case 100..199:
		damage = 10 + random(5);
		cost = 35;
		break;
		default:
		damage = 10;
		cost = 30;
		break;
	}
	
		
	if(User->query_sp() < cost){
		write(RED+"Adroushan"+NORM+" says: You are too drained to attempt this!!.\n");
		return 1;
	}
	
	switch(PO->query_fdagger()){
		case 400..500:
		msg1 = "raise your hands "+YEL+"summoning "+NORM+RED+"fire daggers"+NORM+" as they fly towards "+attacker->query_name()+ RED+" E R R A D I C A T I N G"+NORM+" them, into a pile of smoldering ash";
		msg2 = " raises "+User->query_possessive()+" hands "+YEL+"summoning "+NORM+RED+"fire daggers"+NORM+" as they fly towards you"+ RED+" E R R A D I C A T I N G"+NORM+" you, into a pile of smoldering ash";
		msg3 = " raises "+User->query_possessive()+" hands "+YEL+"summoning "+NORM+RED+"fire daggers"+NORM+" as they fly towards "+attacker->query_name()+ RED+" E R R A D I C A T I N G"+NORM+" them, into a pile of smoldering ash";
		break;
		case 300..399:
		msg1 = "raise your hands "+YEL+"summoning "+NORM+RED+"fire daggers"+NORM+" as they fly towards "+attacker->query_name()+", as they"+ RED+" scream"+NORM+" in agony as they"+HIR+" blaze"+NORM+" and smoke";
		msg2 = " raises "+User->query_possessive()+" hands "+YEL+"summoning "+NORM+RED+"fire daggers"+NORM+" as they fly towards you, as you"+ RED+" scream"+NORM+" in agony as you"+HIR+" blaze"+NORM+" and smoke";
		msg3 = " raises "+User->query_possessive()+" hands "+YEL+"summoning "+NORM+RED+"fire daggers"+NORM+" as they fly towards "+attacker->query_name()+", as they"+ RED+" scream"+NORM+" in agony as they"+HIR+" blaze"+NORM+" and smoke";
		break;
		case 200..299:
		msg1 = "raise your hands "+YEL+"summoning "+NORM+RED+"fire daggers"+NORM+" as they fly towards "+attacker->query_name()+ RED+" impaling"+NORM+" them deep in the chest as "+HIR+"blood "+NORM+"flows";
		msg2 = " raises "+User->query_possessive()+" hands "+YEL+"summoning "+NORM+RED+"fire daggers"+NORM+" as they fly towards you"+RED+" impaling"+NORM+" you deep in the chest as "+HIR+"blood "+NORM+"flows";
		msg3 = " raises "+User->query_possessive()+" hands "+YEL+"summoning "+NORM+RED+"fire daggers"+NORM+" as they fly towards "+attacker->query_name()+RED+" impaling"+NORM+" them deep in the chest as "+HIR+"blood "+NORM+"flows";
		break;
		case 100..199:
		msg1 = "raise your hands "+YEL+"summoning "+NORM+RED+"fire daggers"+NORM+" as they fly towards "+attacker->query_name()+", "+HIR+"flaying"+YEL+" flesh"+NORM+" from the bone";
		msg2 = " raises "+User->query_possessive()+" hands "+YEL+"summoning "+NORM+RED+"fire daggers"+NORM+" as they fly towards you"+HIR+", flaying"+YEL+" flesh"+NORM+" from the bone";
		msg3 = " raises "+User->query_possessive()+" hands "+YEL+"summoning "+NORM+RED+"fire daggers"+NORM+" as they fly towards "+attacker->query_name()+HIR+", Flaying"+YEL+" Flesh"+NORM+" from the bone";
		break;
		default:
		msg1 = "raise your hands "+YEL+"summoning "+NORM+RED+"fire daggers"+NORM+" as they fly towards "+attacker->query_name()+", leaving small scratches";
		msg2 = " raises "+User->query_possessive()+" hands "+YEL+"summoning "+NORM+RED+"fire daggers"+NORM+" as they fly towards you, leaving small scratches";
		msg3 = " raises "+User->query_possessive()+" hands "+YEL+"summoning "+NORM+RED+"fire daggers"+NORM+" as they fly towards "+attacker->query_name()+" leaving small scratches";
		break;
	}
	
	if(PO->query_firebond())
	{
		damage *= 4;
		damage /= 3;
	}
	
	if(attacker->is_sprayed())
	{
		damage /= 5;
		damage *= 6;
	}
	
	User->spell_object(attacker, "fdagger", damage, cost, "You "+msg1+".\n", User->query_name()+msg2+".\n", User->query_name()+msg3+".\n");
	User->set_spell_dtype("other|fire");
	
	if(PO->query_airshroud())
	{
		if(chance < 15)
		{
			write(YEL+"\n\nAeolos grants you the energy to attack again!\n\n"+NORM);
			User->set_spell_dam(0);
		}
	}
	
	switch(randagger){
		case 0..1:
			if(PO->query_fdagger() < 500){
				PO->add_fdagger(1);
			}
		break;
		case 3..4:
			if(PO->query_fdagger() < 500){
				PO->add_fdagger(2);
			}
		break;
		default:
			if(PO->query_fdagger() < 500){
				PO->add_fdagger(3);
			}
		break;
	}
		
	return 1;
}
