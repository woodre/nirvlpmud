#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	int damage, damage2, cost, ranblast, chance;
	object attacker, victim;
	string msg1, msg2, msg3, tname;
	
	ranblast = random(5);
	chance = random(99);
        damage2 =0;
	
	if(PO->query_suspend())
	{
		write(CYN+"Glyndwr"+NORM+" says: You have lost your rights to do this. You are suspended.\n");
		return 1;
	}
	
	if(PO->query_WATER() < 1)
	{
		write(CYN+"Glyndwr"+NORM+" says: You do not have the knowledge of this spell yet, young one!\n");
		return 1;
	}
		
	if(User->query_ghost()){
		return 1;
	}
	
	if(User->query_spell_dam()){
		write(CYN+"Glyndwr"+NORM+" says: Slow down. You cannot attack again just yet!\n");
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
		write(CYN+"Glyndwr"+NORM+" says: I'm sorry but there is no"+RED+" "+str+" "+NORM+"here.\n");
		return 1;
	}
	if(!living(attacker)){
		write(CYN+"Glyndwr"+NORM+" says: I'm sorry but how are you suppose to attack that?\n");
		return 1;
	}
	
	switch(PO->query_iceblast()){
		case 400..500:
		damage = 35 + random(20);
		cost = 45;
		break;
		case 300..399:
		damage = 25 + random(15);
		cost = 33;
		break;
		case 200..299:
		damage = 20 + random(10);
		cost = 25;
		break;
		case 100..199:
		damage = 10 + random(5);
		cost = 13;
		break;
		default:
		damage = 10;
		cost = 10;
		break;
	}
	
		
	if(User->query_sp() < cost){
		write(CYN+"Glyndwr"+NORM+" says: You are too drained to attempt this!!.\n");
		return 1;
	}
	
	tname = (string)attacker->query_name();
	
	switch(PO->query_iceblast()){
		case 375..500:
		msg1 = "pray to "+HIB+"Glyndwr"+NORM+" asking for help in summoning "+HIB+"Ice Shards"+NORM+" to damage "+attacker->query_objective()+".\nThe Ice Shards shave layers of skin off of "+attacker->query_objective()+"";
		msg2 = " prays to "+HIB+"Glyndwr"+NORM+" asking for help in summoning "+HIB+"Ice Shards"+NORM+" to damage you!\nThe Ice Shards shave layers of skin off of you";
		msg3 = " prays to "+HIB+"Glyndwr"+NORM+" asking for help in summoning "+HIB+"Ice Shards"+NORM+" to damage "+attacker->query_name()+"!\nThe Ice Shards shave layers of skin off of "+attacker->query_objective()+"";
		break;
		case 250..374:
		msg1 = "pray to "+HIB+"Glyndwr"+NORM+" asking for help in summoning "+HIB+"Ice Shards"+NORM+" to damage "+attacker->query_objective()+".\n The Ice Shards shred "+attacker->query_possessive()+" skin making him "+HIR+"bleed"+NORM;
		msg2 = " prays to "+HIB+"Glyndwr"+NORM+" asking for help in summoning "+HIB+"Ice Shards"+NORM+" to damage you!\nThe Ice Shards shred your skin making you "+HIR+"bleed"+NORM;
		msg3 = " prays to "+HIB+"Glyndwr"+NORM+" asking for help in summoning "+HIB+"Ice Shards"+NORM+" to damage "+attacker->query_name()+"!\nThe Ice Shards shred "+attacker->query_objective()+" skin making "+attacker->query_objective()+" "+HIR+"bleed"+NORM;
		break;
		case 125..249:
		msg1 = "pray to "+HIB+"Glyndwr"+NORM+" asking for help in summoning "+HIB+"Ice Shards"+NORM+" to damage "+attacker->query_objective()+".\nThe Ice Shards leave "+attacker->query_objective()+" with cuts";
		msg2 = " prays to "+HIB+"Glyndwr"+NORM+" asking for help in summoning "+HIB+"Ice Shards"+NORM+" to damage you!\nThe Ice Shards leave you with cuts";
		msg3 = " prays to "+HIB+"Glyndwr"+NORM+" asking for help in summoning "+HIB+"Ice Shards"+NORM+" to damage "+attacker->query_name()+"!\nThe Ice Shards leave "+attacker->query_objective()+" with cuts";
		break;
		default:
		msg1 = "pray to "+HIB+"Glyndwr"+NORM+" asking for help in summoning "+HIB+"Ice Shards"+NORM+" to damage "+attacker->query_objective()+".\nThe Ice Shards leave small scratches";
		msg2 = " prays to "+HIB+"Glyndwr"+NORM+" asking for help in summoning "+HIB+"Ice Shards"+NORM+" to damage you!\nThe Ice Shards leave small scratches";
		msg3 = " prays to "+HIB+"Glyndwr"+NORM+" asking for help in summoning "+HIB+"Ice Shards"+NORM+" to damage "+attacker->query_name()+"!\nThe Ice Shards leave small scratches";
		break;
	}
	
	if(PO->query_waterbond())
	{
		damage *= 4;
		damage /= 3;
	}
	
	if(attacker->is_sprayed())
	{
		damage /= 5;
		damage *= 6;
	}
	
    if(damage > 50)
    {
       damage2 = damage - 50;
       damage = 50;
    }
    
    victim = (object)this_player()->query_attack();
  	User->set_spell_dam(1);
  	User->add_spell_point(-cost);
  	write("You "+msg1+"!\n");
  	say(User->query_name()+msg3+"!\n");
  	attacker->do_damage(({damage}), ({"other|water"}));
  	if(victim) attacker->do_damage(({damage2}), ({"other|water"}));
        
	/*User->spell_object(attacker, "iceblast", damage, cost, "You "+msg1+".\n", User->query_name()+msg2+".\n", User->query_name()+msg3+".\n");
	User->set_spell_dtype("other|water");
	
       attacker->do_damage(({damage2}), ({"other|water"}));*/
 
	if(PO->query_airshroud())
	{
		if(chance < 15){
			write(HIR+"\n\nAeolos grants you the energy to attack again!\n\n"+NORM);
			User->set_spell_dam(0);
		}
	}
	
	switch(ranblast){
		case 0..1:
			if(PO->query_iceblast() < 500){
				PO->add_iceblast(1);
			}
		break;
		case 3..4:
			if(PO->query_iceblast() < 500){
				PO->add_iceblast(2);
			}
		break;
		default:
			if(PO->query_iceblast() < 500){
				PO->add_iceblast(3);
			}
		break;
	}
		
	return 1;
}
