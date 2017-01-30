#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	int damage, cost, ranshard, chance;
	object attacker, airshroud;
	string msg1, msg2, msg3;
	
	ranshard = random(5);
	chance = random(99);
	airshroud = present("wicket_air_shroud", User);
	
	if(PO->query_suspend())
	{
		write(GRN+"Aatami"+NORM+" says: You have lost your rights to do this. You are suspended.\n");
		return 1;
	}
	
	if(PO->query_EARTH() < 1)
    {
    	write(GRN+"Aatami"+NORM+" says: You do not have the knowledge of this spell yet, young one!\n");
    	return 1;
    }
		
	if(User->query_ghost()){
		return 1;
	}
	
	if(User->query_spell_dam()){
		write(GRN+"Aatami"+NORM+" says: Slow down. You cannot attack again just yet!\n");
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
		write(GRN+"Aatami"+NORM+" says: I'm sorry but there is no "+RED+str+NORM+" here.\n");
		return 1;
	}
	if(!living(attacker)){
		write(GRN+"Aatami"+NORM+" says: I'm sorry but how are you suppose to attack that?\n");
		return 1;
	}
	
	switch(PO->query_cshards()){
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
		write(GRN+"Aatami"+NORM+" says: You are too drained to attempt this!\n");
		return 1;
	}
	
	switch(PO->query_cshards()){
		case 400..500:
		msg1 = "send "+CYN+"crystals shards"+NORM+" ripping through "+attacker->query_name()+"'s "+RED+"heart"+NORM;
		msg2 = " sends "+CYN+"crystals shards"+NORM+" RIPPING through your "+RED+"heart"+NORM;
		msg3 = " summons "+CYN+"crystals shards"+NORM+" to RIP through "+attacker->query_name()+"'s "+RED+"heart"+NORM;
		break;
		case 300..399:
		msg1 = "raise your hands "+BOLD+"summoning "+NORM+CYN+"crystals shards"+NORM+" as they fly towards "+attacker->query_name()+RED+" shredding"+NORM+" them into a"+HIR+" bloody"+NORM+" mess";
		msg2 = " raises "+User->query_possessive()+" hands "+BOLD+"summoning "+NORM+CYN+"crystals shards"+NORM+" as they fly towards you"+RED+" shredding"+NORM+" you into a"+HIR+" bloody"+NORM+" mess";
		msg3 = " raises "+User->query_possessive()+" hands "+BOLD+"summoning "+NORM+CYN+"crystals shards"+NORM+" as they fly towards "+attacker->query_name()+RED+" shredding"+NORM+" them into a"+HIR+" bloody"+NORM+" mess";
		break;
		case 200..299:
		msg1 = "raise your hands "+BOLD+"summoning "+NORM+CYN+"crystals shards"+NORM+" as they fly towards "+attacker->query_name()+RED+" impaling"+NORM+" them deep in the chest as "+HIR+"blood "+NORM+"flows";
		msg2 = " raises "+User->query_possessive()+" hands "+BOLD+"summoning "+NORM+CYN+"crystals shards"+NORM+" as they fly towards you"+RED+" impaling"+NORM+" you deep in the chest as "+HIR+"blood "+NORM+"flows";
		msg3 = " raises "+User->query_possessive()+" hands "+BOLD+"summoning "+NORM+CYN+"crystals shards"+NORM+" as they fly towards "+attacker->query_name()+RED+" impaling"+NORM+" them deep in the chest as "+HIR+"blood "+NORM+"flows";
		break;
		case 100..199:
		msg1 = "raise your hands "+BOLD+"summoning "+NORM+CYN+"crystals shards"+NORM+" as they fly towards "+attacker->query_name()+", "+HIR+"Flaying"+YEL+" Flesh"+NORM+" from the bone";
		msg2 = " raises "+User->query_possessive()+" hands "+BOLD+"summoning "+NORM+CYN+"crystals shards"+NORM+" as they fly towards you, "+HIR+" Flaying"+YEL+" Flesh"+NORM+" from the bone";
		msg3 = " raises "+User->query_possessive()+" hands "+BOLD+"summoning "+NORM+CYN+"crystals shards"+NORM+" as they fly towards, "+attacker->query_name()+HIR+" Flaying"+YEL+" Flesh"+NORM+" from the bone";
		break;
		default:
		msg1 = "raise your hands "+BOLD+"summoning "+NORM+CYN+"crystals shards"+NORM+" as they fly towards "+attacker->query_name()+", leaving small scratches";
		msg2 = " raises "+User->query_possessive()+" hands "+BOLD+"summoning "+NORM+CYN+"crystals shards"+NORM+" as they fly towards you, leaving small scratches";
		msg3 = " raises "+User->query_possessive()+" hands "+BOLD+"summoning "+NORM+CYN+"crystals shards"+NORM+" as they fly towards "+attacker->query_name()+" leaving small scratches";
		break;
	}
	
	if(PO->query_earthbond())
	{
		damage *= 4;
		damage /= 3;
	}
	
	if(attacker->is_sprayed())
	{
		damage /= 5;
		damage *= 6;
	}
	
	User->spell_object(attacker, "cshards", damage, cost, "You "+msg1+".\n", User->query_name()+msg2+".\n", User->query_name()+msg3+".\n");
	User->set_spell_dtype("other|earth");
	
	if(PO->query_airshroud())
	{
		if(chance < 15){
			write(YEL+"\n\nAeolos grants you the energy to attack again!\n\n"+NORM);
			User->set_spell_dam(0);
		}
	}
	
	switch(ranshard){
		case 0..1:
			if(PO->query_cshards() < 500){
				PO->add_cshards(1);
			}
		break;
		case 3..4:
			if(PO->query_cshards() < 500){
				PO->add_cshards(2);
			}
		break;
		default:
			if(PO->query_cshards() < 500){
				PO->add_cshards(3);
			}
		break;
	}
		
	return 1;
}
