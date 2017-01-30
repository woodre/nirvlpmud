#include <ansi.h>
#include "/players/wicket/guild/defs.h"

status main(string str, object PO, object User)
{
	object drown, attacker;
	int randomtsunami, length, damage;
	int percentage, chance;
	
	randomtsunami = random(5);
	percentage = random(101);
	chance = random(99);
	
	if(PO->query_suspend())
	{
		write(CYN+"Glyndwr"+NORM+" says: You have lost your rights to do this. You are suspended.\n");
		return 1;
	}
	
	if(User->query_ghost()){
		return 1;
	}
	
	if(PO->query_WATER() < 7){
		write(CYN+"Glyndwr"+NORM+" says: You do not have the knowledge of this spell yet, young one!\n");
		return 1;
	}
	
	if(User->query_sp() < 40){
		write(CYN+"Glyndwr"+NORM+" says: You are too drained to attempt this!\n");
		return 1;
	}
	
	if(User->query_spell_dam()){
		write(CYN+"Glyndwr"+NORM+" says: Slow down. You cannot yet attack again!\n");;
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
		write(CYN+"Glyndwr"+NORM+" says: I'm sorry but how are you suppose to attack that?\n");
		return 1;
	}
	
	switch(PO->query_tsunami()){
		case 666..1000:
		length = 10;
		damage = 20 + random(11);
		break;
		case 333..665:
		length = 5;
		damage = 10 + random(11);
		break;
		default:
		length = 3;
		damage = 10;
		break;
	}
	
	if(PO->query_waterbond())
	{
		damage *= 2;
	}
	
	if(attacker->is_sprayed())
	{
		damage /= 5;
		damage *= 6;
		tell_room(User, "Multiply_Damage_Bitch\n");
	}
	
	User->spell_object(attacker, "tsunami", damage, 40, BOLD+"You summon a giant "+NORM+CYN+"tsunami"+NORM+BOLD+" to overcome your enemy!\n"+NORM, BOLD+User->query_name()+" summons a giant "+NORM+CYN+"tsunami"+NORM+BOLD+" to overcome you!\n"+NORM, BOLD+User->query_name()+" summons a giant "+NORM+CYN+"tsunami"+NORM+BOLD+" to overcome "+possessive(User)+" enemy.\n"+NORM);
	User->set_spell_dtype("other|water");
	User->add_spell_point(-40);
	
	if(PO->query_airshroud())
	{
		if(chance < 15){
			write(YEL+"\n\nAeolos grants you the energy to attack again!\n\n"+NORM);
			User->set_spell_dam(0);
		}
	}
	
	if(percentage < 35 && !present("water_damage_bitch", attacker))   /* 35% chance */
	{
		drown = clone_object("/players/wicket/guild/objs/waterdam.c");
		move_object(drown, attacker);
		drown->set_damlength(length);
		drown->start_it();
		write(CYN+"Water "+NORM+BOLD+"fills "+attacker->query_name()+"'s lungs!\n"+NORM);
	}
	
	switch(randomtsunami){
		case 0..1:
			if(PO->query_tsunami() < 995){
				PO->add_tsunami(1);
			}
		break;
		case 3..4:
			if(PO->query_tsunami() < 995){
				PO->add_tsunami(2);
			}
		break;
		default:
			if(PO->query_tsunami() < 995){
				PO->add_tsunami(3);
			}
		break;
	}		
	return 1;
}