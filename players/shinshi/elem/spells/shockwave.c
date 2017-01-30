#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	int miss, stun, damage, ranswave;
	int missnum, stunnum, cost, chance;
	object stunobj, attacker;
	string msg1, msg2, msg3;
	
	miss = random(101);
	stun = random(101);
	damage = 5 + random(6);
	ranswave = random(5);
	
	stunobj = clone_object("/players/wicket/guild/objs/stunobj.c");
	
	if(PO->query_suspend())
	{
		write(GRN+"Aatami"+NORM+" says: You have lost your rights to do this. You are suspended.\n");
		return 1;
	}
	
	if(User->query_ghost()){
		return 1;
	}
	
	if(PO->query_EARTH() < 3)
	{
		write(GRN+"Aatami"+NORM+" says: You do not have the knowledge of this spell yet, young one!\n");
		return 1;
	}
	
	if(User->query_spell_dam()){
		write(GRN+"Aatami"+NORM+" says: You cannot attack again so soon!\n");
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
	
	if(attacker->query_level() > 20)
	{
		write(GRN+"Aatami"+NORM+" says: Even I am not foolish enough to try that on a wizard.\n");
		return 1;
	}
	
	switch(PO->query_shockwave()){   /* Damage, Miss, Stun chances */
		case 400..500:
		missnum = 64;
		stunnum = 69;
		cost = 40;
		break;
		case 300..399:
		missnum = 54;
		stunnum = 59;
		cost = 30;
		break;
		case 200..299:
		missnum = 44;
		stunnum = 49;
		cost = 25;
		break;
		case 100..199:
		missnum = 34;
		stunnum = 39;
		cost = 15;
		break;
		default:
		missnum = 24;
		stunnum = 29;
		cost = 10;
		break;
	}
	
		
	if(User->query_sp() < cost){
		write(GRN+"Aatami"+NORM+" says: You are too drained to attempt this!!.\n");
		return 1;
	}
	
	if(miss < missnum)
	{
		write(HIR+"Your shockwave misses your target!\n"+NORM);
		User->set_spell_dam(1);
		switch(ranswave){
			case 0..1:
				if(PO->query_shockwave() < 500){
					PO->add_shockwave(1);
				}
			break;
			case 3..4:
				if(PO->query_shockwave() < 500){
					PO->add_shockwave(2);
				}
			break;
			default:
				if(PO->query_shockwave() < 500){
					PO->add_shockwave(3);
				}
			break;
		}
		return 1;
	}
	
	msg1 = "summon a massive shockwave to leave the area in shambles";
	msg2 = " summons a massive shockwave, leaving the area in shambles";
	msg3 = " summons a massive shockwave, leaving the area in shambles";
	
	if(PO->query_earthbond())
	{
		damage *= 4;
		damage /= 3;
	}
	
	if(attacker->is_sprayed())
	{
		damage /= 5;
		damage *= 6;
		tell_room(User, "Multiply_Damage_Bitch\n");
	}
	
	User->spell_object(attacker, "shockwave", damage, cost, HIY+"You "+msg1+"!\n"+NORM, HIY+User->query_name()+msg2+"!\n"+NORM, HIY+User->query_name()+msg3+"!\n"+NORM);
	User->set_spell_dtype("other|earth");
	
	if(PO->query_airshroud())
	{
		if(chance < 15){
			write(YEL+"\n\nAeolos grants you the energy to attack again!\n\n"+NORM);
			User->set_spell_dam(0);
		}
	}
	
	if((stun < stunnum) && !present("shockwave_stun_bitch", attacker))
	{
		move_object(stunobj, attacker);
		write("The shockwave leaves "+attacker->query_name()+" stunned!\n");
		tell_object(attacker, "The shockwave leaves you stunned!\n");
		say("The shockwave leaves "+attacker->query_name()+" stunned!\n");
		stunobj->start_it();
	}

	
	switch(ranswave){
		case 0..1:
			if(PO->query_shockwave() < 500){
				PO->add_shockwave(5);
			}
		break;
		case 3..4:
			if(PO->query_shockwave() < 500){
				PO->add_shockwave(10);
			}
		break;
		default:
			if(PO->query_shockwave() < 500){
				PO->add_shockwave(15);
			}
		break;
	}
		
	return 1;
}
