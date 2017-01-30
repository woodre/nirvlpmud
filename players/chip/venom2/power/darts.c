/*
Level 2 Combat Spell: Darts -  Attack spell that can be fired from the backline
only. This means they cannot be attacked directly, but can be attacking.
Cost is combat*2 + combat*4/2 & Mp 1.  Damage: combat *2 + r(combat*5)
At level 6 Combat and level 6 Control it begins to Wound.  Damage 1-3 for
r(3) + 1 times.  25% chance of wound.
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
	if(COM < 2) return 0;
	if(USER->query_spell_dam()) return 1;
	if(GOB->query_spell_delay()){
		tell_object(USER,
		"You are already using "+GOB->query_spell_delay()+".\n");
		return 1;
	}
	if(USER->query_sp() < COM + ((COM*4)/2)){
		tell_object(USER,
		"Your symbiotic link is too weak for that.\n");
		return 1;
	}
	if(!USER->query_attack()){
		tell_object(USER, COLOR+"You are not fighting!"+NORM+"\n");
		return 1;
	}
	if(GOB->check_attackers()){
		tell_object(USER, COLOR+"You are being attacked and cannot do that!"+NORM+"\n");
		return 1;
	}
	
	damage = random(COM * 5) + COM * 2 + 3; /* added the + 3 at the end...if you've ever faught against a max Samurai, you'll understand ;) -Chip(4-17-09)*/
	spamount = COM + ((COM*4)/2);
	
	tell_object(USER,
	COLOR+"<"+NORM+BOLD+"Darts"+NORM+COLOR+">"+NORM+" You hold up your palm out towards your opponent...\n\n");
	if(damage > 6){
		tell_object(USER, "     ");
		for(i = 0; i < damage / 6; i++){
			if(!random(2)) tell_object(USER, "  "+BOLD+"__ "+NORM+"");
			else tell_object(USER, "  "+BOLD+"-- --- "+NORM+"");
		}
		tell_object(USER, "\n\n");
	}
	else{
		tell_object(USER, "             "+BOLD+"- ---          --- -    "+NORM+" \n");
	}
	GOB->add_mp(-1);
	tell_object(USER, "\n\n");
	tell_room(environment(USER),
		USER->query_name()+" holds "+USER->POS+" hand palm outward and fires off "+
	" "+((damage / 5)+1)+" "+HIK+"Dark Matter"+NORM+" Darts into "+ATTN+".\n", ({ USER }));
	target = USER->query_attack();
	msg   = "";
	msg2 = "";
	msg3 = "";
	USER->spell_object(target, BOLD+"Darts"+NORM, damage, spamount,
	msg, msg2, msg3);
	if(random(100) < 33 && !present("wounded_object_venom", target) && COM > 5){ /* upped chance to wound from 20% to 33%. reasonable as other guilds have manual wound spells -Chip(4-15-09)*/
		wound = clone_object("/players/chip/venom2/OBJ/wound.c");
		wound->set_how_many(random(2) + 3); /* changed from wound->set_how_many(random(3) + 1);. other guilds' wound type spells last longer than this by a good bit, so it's only fair -Chip(4-17-09)*/
		move_object(wound, target);
	}
	return 1;
}

