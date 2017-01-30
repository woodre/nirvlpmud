/*  Level 1 Combat Spell: Wep -   Uses the shapetype from the old and makes a
frontline spell attack vs. opponents.  +20 WC, No randomization because the
lib does it for us.  sp cost: 40    THIS IS THE MAIN SPELL - NOT Darts  */

#include "/players/chip/venom2/sdefine.h"


main(string str, object gob, object player)
{
	object target;
	int woot;
	string msg,msg2,msg3;
	int damage,spamount;
	string wep,where,how;
	if(USER->query_ghost()) return 0;
	if(COM < 1) return 0;
	if(USER->query_spell_dam()) return 1;
	if(GOB->query_spell_delay()){
		tell_object(USER,
		"You are already using "+GOB->query_spell_delay()+".\n");
		return 1;
	}
	if(USER->query_sp() < 40){
		tell_object(USER,
		"Your symbiotic link is too weak for that.\n");
		return 1;
	}
	if(!USER->query_attack()){
		tell_object(USER, "You are not fighting!\n");
		return 1;
	}
	
	switch(random(10) + 1){
		case 10:  wep = "BattleAxe"; break;
		case   9:  wep = "Spear"; break;
		case   8:  wep = "Sword"; break;
		case   7:  wep = "WarDagger"; break;
		case   6:  wep = "Whip"; break;
		case   5:  wep = "Claw"; break;
		case   4:  wep = "Mace"; break;
		case   3:  wep = "WarHammer"; break;
		case   2:  wep = "Maul"; break;
		case   1:  wep = "Scythe"; break;
	}
	switch(random(10) + 1){
		case  10: where = "head"; break;
		case    9: where = "hand"; break;
		case    8: where = "arm"; break;
		case    7: where = "leg"; break;
		case    6: where = "thigh"; break;
		case    5: where = "neck"; break;
		case    4: where = "shoulder"; break;
		case    3: where = "stomach"; break;
		case    2: where = "chest"; break;
		case    1: where = "face"; break;
	}

        spamount = 40; /* up from 15 to compensate for upped damage below -Chip(4-17-09)*/
	damage = random(45) + 25; /* up from damage = random(11) + 10; to bring up to date with today's power standards -Chip(4-17-09)*/

	switch(damage){
                case 65..75:  how = HIR+"D E M O L I S H E D"+NORM; break;
                case 57..64: how = RED+"eviscerated"+NORM; break;
                case 48..56: how = HIW+"gored"+NORM; break;
                case 38..47: how = HIW+"disemboweled"+NORM; break;
                case 30..37: how = RED+"ravaged"+NORM; break;
                case 25..29:     how = "Hit"; break;
	}
	tell_object(USER,
	COLOR+"<Weapon>"+NORM+" You shape your arm into a "+wep+"...\n");
	
	tell_object(USER,
	"You "+how+" "+ATTN+" with a "+HIK+"Dark Matter"+NORM+" "+wep+" swing to the "+where+".\n");
	tell_room(environment(USER),
	USER->query_name()+" "+how+" "+ATTN+" with a "+HIK+"Dark Matter"+NORM+" "+wep+" swing to the "+where+".\n", ({ USER }));
	msg = "";
	msg2 = "";
	msg3 = "";
	USER->spell_object(ATT, HIK+"Dark Matter"+BOLD+" Weapon"+NORM, damage, spamount,
	msg, msg2, msg3);
	return 1;
}
