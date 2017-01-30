/*
Level 5 Combat  & Level 5 Control Spell: Suffocate -  Works only on mobs and
does choking damage until it fatals them at 0/10. Suffocation can start at 3/10
and requires the Symbiote to be present to continue it.
Cost: 30 sps and 5 mp. Chance of failure.(see below)
*/

#include "/players/chip/venom2/sdefine.h"


main(string str, object gob, object player)
{
	object target,wound;
	int woot,i;
	string msg,msg2,msg3;
	int damage,spamount;
	string wep,where,how;
	
	if(USER->query_ghost()) return 0;
	if(COM < 5 || CON < 5) return 0;
	if(!USER->query_attack()){
		tell_object(USER, COLOR+"You are not fighting!"+NORM+"\n");
		return 1;
	}
	target = ATT;
	if(!ATT->is_npc()){
		tell_object(USER, "You may only perform this on monsters!\n");
		return 1;
	}
	if(USER->query_sp() < 45){
		tell_object(USER,
		"You lack the energy for that.\n");
		return 1;
	}
        if(GOB->query_mp() < 15){
		tell_object(USER, "You lack the "+HIK+"Dark Matter"+NORM+" to perform that.\n");
		return 1;
	}
	if((ATT->query_hp()*10)/(ATT->query_mhp()) > 4){ /* can now be used if the mob is down to 4/10 rather than 3/10 -Chip(4-17-09)*/
		tell_object(USER, ATTN+" is still too strong!\n");
		return 1;
	}
	if(present("suffocate_object_venom", target)){
		tell_object(USER, "They are already being suffocated!\n");
		return 1;
	}
	if(random(100) > target->query_level()){
		tell_object(USER,
			"You point at "+ATTN+" and send a tentacle out to suffocate them...\n"+
		"The "+HIK+"Dark Matter"+BOLD+" Tentacle"+NORM+" flies outward and implants itself down their throat!\n");
		tell_room(environment(USER),
		"A tentacle of "+HIK+"Dark Matter"+NORM+" flies out towards "+ATTN+" and flies down their throat! "+ATTN+" begins to suffocate!\n", ({USER}));
		wound = clone_object("/players/chip/venom2/OBJ/suffocate.c");
		wound->set_who(USER->query_real_name());
		move_object(wound, target);
	}
	else{
		tell_object(USER, "Your tentacle lashes out to suffocate and misses!\n");
	}
GOB->add_mp(-15);
	USER->add_spell_point(-45);
	return 1;
}

