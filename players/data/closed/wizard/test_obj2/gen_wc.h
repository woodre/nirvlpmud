static object curr_wep;
static int wep_type;
static int skill_br;


gen_wc_bonus(){
	int wep_bonus;
	object ob;
	int strmod,dexmod;
        if(!ATT) return;
	strmod = USER->query_attrib("str");
	dexmod = USER->query_attrib("ste");
	wep_bonus = 0;
	
	ob = USER->query_weapon();
   	
   if(ob && sac_bonus){
		wep_bonus += sac_bonus;
		sac_bonus = 0;
	}

	if(monk) wep_bonus += monk_bonus();
	
	if(set_light(0) > 0 || skills[70]){
		
		if(ob){
			if(archer_check(ob)){
				if(dexmod > 15 && dexmod < 21) wep_bonus += random(2);
				else if(dexmod > 20 && dexmod < 25) wep_bonus += random(3);
				else if(dexmod > 24 && dexmod < 27) wep_bonus += random(4);
				else if(dexmod == 27) wep_bonus += random(5) + 1;
				else if(dexmod == 28) wep_bonus += random(5) + 2;
				else if(dexmod == 29) wep_bonus += random(6) + 3;
				else if(dexmod == 30) wep_bonus += random(8) + 4;
			}
			/* Strength modifier */
			else{
				if(strmod > 15 && strmod < 21) wep_bonus += random(2);
				else if(strmod > 20 && strmod < 25) wep_bonus += random(3);
				else if(strmod > 24 && strmod < 27) wep_bonus += random(4);
				else if(strmod == 27) wep_bonus += random(5) + 1;
				else if(strmod == 28) wep_bonus += random(5) + 2;
				else if(strmod == 29) wep_bonus += random(6) + 3;
				else if(strmod == 30) wep_bonus += random(8) + 4;
			}
			
			
			if(ob != curr_wep || !curr_wep){
				curr_wep = ob;
				wep_type = 0;
				skill_br = 0;
				if(skills[1]){
					if(blunt_check(ob)){
						wep_type = skills[1];
						skill_br = 1;
					}
				}
				
				if(skills[2]){
					if(edged_check(ob)){
						wep_type = skills[2];
						skill_br = 2;
					}
				}
				if(skills[3]){
					if(polearm_check(ob)){
						wep_type = skills[3];
						skill_br = 3;
					}
				}
				if(skills[4]){
					if(archer_check(ob)){
						wep_type = skills[4];
						skill_br = 4;
					}
				}
				if(skills[6]){
					if(small_check(ob)){
						wep_type = skills[6];
						skill_br = 6;
					}
				}
				if(skills[5]){
					if(!wep_type){
						wep_type = skills[5];
						skill_br = 5;
					}
				}
			}
			if(wep_type){
				switch(wep_type * random(10) + 1){
               case 131..10000: wep_bonus += 20;      break;
					case 115..130: wep_bonus += 15;        break;
               case 95..114:  wep_bonus += 13;        break;
					case 85..94:   wep_bonus += 8;         break;
					case 70..84:   wep_bonus += 6;         break;
					case 35..69:   wep_bonus += 4;         break;
					case 20..34:   wep_bonus += 2;         break;
					case 10..19:   wep_bonus += 1;         break;
					case 5..9:     wep_bonus += random(2); break;
					case 1..4:     wep_bonus += 0;         break;
					default:       wep_bonus += 0;         break;
				}
				skill_tier[skill_br] += 1;
			}
			
		}
	}
 
	if(present("stun_object_prof", ATT)) wep_bonus += random(6) + 3;
	if(ATT->pummeled()) wep_bonus += random(6) + 3;
	if(ob && curr_wep)
	if(USER->query_level() > 99){
		tell_object(USER,
		"BONUS>>>> "+wep_bonus+"::"+wep_type+"::"+file_name(ob)+"::"+file_name(curr_wep)+"\n");
	}
	
	return wep_bonus;
}


check_weapon(ob){
	object dawep;
	
	if(!ob){ write("check which weapon?\n"); return 1; }
	dawep = present(ob, USER);
	if(!dawep){ write("You do not see that here!\n"); return 1; }
	if(!dawep->weapon_class()){
		write("It doesn't seem to be a weapon.\n");
		return 1;
	}
	if(blunt_check(dawep)){
		write("The weapon is considered a Blunt type.\n");
		return 1;
	}
	
	else if(edged_check(dawep)){
		write("The weapon is considered a Edged type.\n");
		return 1;
	}
	
	else if(polearm_check(dawep)){
		write("The weapon is considered a Polearm type.\n");
		return 1;
	}
	
	else if(archer_check(dawep)){
		write("The weapon is considered a Bow type.\n");
		return 1;
	}
	else if(small_check(dawep)){
		write("The weapon is considered a Small type.\n");
		return 1;
	}
	else{
		write("The Weapon is considered an Exotic type.\n");
		return 1;
	}
	return 1;
}



blunt_check(dawep){
	if(call_other(dawep,"id", "mace") || call_other(dawep, "id", "club") ||
		call_other(dawep, "id", "flail") || call_other(dawep, "id", "hammer") ||
		call_other(dawep, "id", "morningstar") || call_other(dawep, "id", "stick")){
		return 1;
	}
	return 0;
}

small_check(dawep){
	if(call_other(dawep,"id", "dagger") || call_other(dawep, "id", "knife") ||
		call_other(dawep, "id", "shuriken") || call_other(dawep, "id", "stiletto") ||
		call_other(dawep, "id", "punchknife") || call_other(dawep, "id", "scalpel")){
		return 1;
	}
	return 0;
}

edged_check(dawep){
	if(call_other(dawep, "id", "sword") || call_other(dawep, "id", "saber") ||
		call_other(dawep, "id", "nodachi") || call_other(dawep, "id", "katana") ||
		call_other(dawep, "id", "wakizashi") || call_other(dawep, "id", "blade") ||
		call_other(dawep, "id", "blades") || call_other(dawep, "id", "swords") ||
		call_other(dawep, "id", "rapier") || call_other(dawep, "id", "axe") ||
		call_other(dawep, "id", "battleaxe") || call_other(dawep, "id", "scimitar")){
		return 1;
	}
	return 0;
}

polearm_check(dawep){
	if(call_other(dawep,"id", "polearm") || call_other(dawep, "id", "halberd") ||
		call_other(dawep, "id", "scythe") || call_other(dawep, "id", "naginata") ||
		call_other(dawep, "id", "spear") || call_other(dawep, "id", "staff") ||
		call_other(dawep, "id", "lance") || call_other(dawep, "id", "javelin") ||
		call_other(dawep, "id", "trident")){
		return 1;
	}
	return 0;
}

archer_check(dawep){
	if(call_other(dawep,"id", "bow") || call_other(dawep, "id", "crossbow") ||
		call_other(dawep, "id", "chaingun") || call_other(dawep, "id", "gun") ||
		call_other(dawep, "id", "rifle") || call_other(dawep, "id", "pistol") ||
		call_other(dawep, "id", "cannon") || call_other(dawep, "id", "longbow") ||
		call_other(dawep, "id", "daikyu") || call_other(dawep, "id", "laser") ||
		call_other(dawep, "id", "boomerang")){
		return 1;
	}
	return 0;
}

exotic_check(dawep){
	if(!blunt_check(dawep) && !small_check(dawep) && !edged_check(dawep) &&
		!polearm_check(dawep) && !archer_check(dawep)){
		return 1;
	}
	return 0;
}

shield_check(){
	object inv;
	int x;
	int woo;
	inv = all_inventory(USER);
	for(x = 0; x < sizeof(inv); x++){
		if(inv[x]->query_worn() && inv[x]->query_type() == "shield"){
			return 1;
		}
	}
	return 0;
}
