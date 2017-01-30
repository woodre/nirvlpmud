/*  
XThrow <wep> 
Skill Range: 1-5
Cost: 20 sp + 2 endurance
Drawback: Requires a free wep and pk
*/

#include "/players/maledicta/closed/w/sdefine.h"


main(string str, object gob, object player)
{
	object target;
	int woot,bonus,bonus2;
	object wep;
	int ok;
	int ks;
	string msg,msg2,msg3;
	int damage,spamount;
	string where,how;
	if(USER->query_ghost()) return 0;
	if(USER->query_spell_dam()) return 1;
	if(!USER->query_pl_k()){
		tell_object(USER, "Assassins must be pk.\n");
		return 1;
	}
	if(!GOB->get_skill(70)){
		if(USER->test_dark()){
			return 1;
		}
	} 
	if(GOB->query_end() < 2){
		tell_object(USER,
			"You are too tired.\n");
		return 1;
	}
	if(GOB->query_spell_delay()){
		tell_object(USER,
			"You are already casting.\n");
		return 1;
	}
	if(!str && !present("knife_belt", USER)){ tell_object(USER,"Throw what?\n"); return 1; }
	else if(!str && present("knife_belt", USER)){
		if(present("knife_belt", USER)->query_ammo()){
			ks = 1;
		}
	}
	if(!ks && !str){ tell_object(USER, "Throw what?\n"); return 1; }
	if(!ks){
		wep = present(str, USER);

		if(!wep){ tell_object(USER,"You don't seem to have that!\n"); return 1; }
		if(!wep->weapon_class() || !wep->is_weapon()){
			tell_object(USER, "You can't throw that!\n");
			return 1;
		}
		if(wep->query_wielded()){ 
			tell_object(USER,"You don't want to throw your wielded weapon!\n");
			return 1;
		}
		if(call_other(wep,"id", "dagger") || call_other(wep, "id", "knife") ||
			call_other(wep, "id", "shuriken") || call_other(wep, "id", "stiletto") ||
			call_other(wep, "id", "punchknife") || call_other(wep, "id", "scalpel")){
				ok = 1;
				if(GOB->get_skill(6)) bonus2 = GOB->get_skill(6);
			}
		else if(call_other(wep,"id", "sword") || call_other(wep, "id", "saber") ||
			call_other(wep, "id", "nodachi") || call_other(wep, "id", "katana") ||
			call_other(wep, "id", "wakizashi") || call_other(wep, "id", "blade") ||
			call_other(wep, "id", "blades") || call_other(wep, "id", "swords") ||
			call_other(wep, "id", "rapier") || call_other(wep, "id", "axe") ||
			call_other(wep, "id", "battleaxe") || call_other(wep, "id", "scimitar")){
				ok = 1;
				if(GOB->get_skill(2)) bonus2 = GOB->get_skill(2);
			}
			if(!ok){ tell_object(USER, "You cannot throw that!\n"); return 1; }
	}    

	if(USER->query_sp() < 20){
		tell_object(USER,
			"You are too tired to throw.\n");
		return 1;
	}
	if(!USER->query_attack()){
		tell_object(USER, "You are not fighting!\n");
		return 1;
	}

	switch((random(GOB->get_skill(116)) * 20) + 1){
		case   60..1000: where = "head"; bonus = 13; break;
		case   45..59: where = "neck"; bonus = 9; break;
		case   30..44: where = "stomach"; bonus = 7; break;
		case   20..29: where = "chest"; bonus = 5; break;
		case   10..19: where = "thigh"; bonus = 4; break;
		case   5..9:   where = "shoulder"; bonus = 3; break;
		case   3..4:   where = "arm"; bonus = 2; break;
		case   1..2:   where = "leg"; bonus = 1; break;
		case    0: where = "chest"; break;
		default: where = "nowhere"; break;
	}

	spamount = 20;
	if(!ks){
		damage = random(wep->weapon_class()) + bonus + random(STE/2) + 5;
		if(bonus2) damage += random(bonus2);

		tell_object(USER,
			BOLD+"<"+NORM+RED+"<"+HIR+"< X >"+NORM+RED+">"+NORM+BOLD+">"+NORM+"\n"+
			" You launch the "+wep->short()+" through the air...\n");
		tell_object(USER,
			"The "+str+" plunges into "+ATTN+"'s "+where+"!\n");

		tell_room(environment(USER),
			USER->query_name()+" launches a "+wep->short()+" through the air..."+
			"It buries into "+ATTN+"'s "+where+"!\n", ({ USER }));
	}
	else{
		if(GOB->get_skill(6)) bonus2 += GOB->get_skill(6);
		damage = random(14) + bonus + random(STE/2) + 5;
		if(bonus2) damage += random(bonus2);

		tell_object(USER,
			BOLD+"<"+NORM+RED+"<"+HIR+"< X >"+NORM+RED+">"+NORM+BOLD+">"+NORM+"\n"+
			" You launch the Throwing Knife through the air...\n");
		tell_object(USER,
			"The Knife plunges into "+ATTN+"'s "+where+"!\n");

		tell_room(environment(USER),
			USER->query_name()+" launches a Throwing Knife through the air..."+
			"It buries into "+ATTN+"'s "+where+"!\n", ({ USER }));
	}
	if(wep) destruct(wep);
	else present("knife_belt", USER)->minus_one();
	USER->recalc_carry();
	msg = "";
	msg2 = "";
	msg3 = "";
	GOB->add_end(-2);
	USER->spell_object(ATT, "Xthrow", damage, spamount,
		msg, msg2, msg3);
	return 1;
}
