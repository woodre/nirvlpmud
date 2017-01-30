

/******************** Paladin Schtuff *************/
static regen_aura;
static sac_bonus;
static good_aura;   /* Protection from good */
static evil_aura;   /* Protection from evil */
string chosen_align;
set_regen_aura(int i){ regen_aura = i; }
query_regen_aura(){ return regen_aura; }
set_good_aura(int i){ good_aura = i; }
query_good_aura(){ return good_aura; }
set_evil_aura(int i){ evil_aura = i; }
query_evil_aura(){ return evil_aura; }

set_chosen_align(str){ chosen_align = str; }
query_chosen_align(){ return chosen_align; }

query_paladin(){ return paladin; }
set_paladin(int i){ paladin = i; }

query_aura(){
	if(regen_aura || good_aura || evil_aura) return 1;
	return 0;
}
int hdelay;
set_hdelay(int i){ hdelay = i; }
query_hdelay(){ return hdelay; }

int delay;
set_delay(int i){ delay = i; }
query_delay(){ return delay; }
query_spell_delay(){ return delay; }
set_spell_delay(int i){ delay = i; }

check_align(str){
  int align;
 align = USER->query_alignment();

if(!str){
   if(chosen_align == "good"){
   if(align > 40) return 1;
   return 0;
   }
  if(chosen_align == "evil"){
   if(align > 0) return 0;
   align = - align;
   if(align > 40) return 1;
   return 0;
   }
 return 0;
 }
if(str == "good"){
 if(align > 40) return 1;
   return 0;
   }
if(str == "evil"){
 if(align > 0) return 0;
   align = - align;
   if(align > 40) return 1;
   return 0;
   }
return 0;
}



/*************************** CMDS FOR PALADIN ***************/
release_cmd(str){
   if(!check_align()){
      tell_object(USER,
      "Your alignment robs you of your abilities!\n");
      return 1;
      }
	if(set_light(0) <= 0 && !skills[70]){ write("It is too dark.\n"); return 1; }
	if(skills[94]){ "/players/data/closed/wizard/power/release.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}

cleanse_cmd(str){
   if(!check_align()){
      tell_object(USER,
      "Your alignment robs you of your abilities!\n");
      return 1;
      }
	if(set_light(0) <= 0 && !skills[70]){ write("It is too dark.\n"); return 1; }
	if(skills[95]){ "/players/data/closed/wizard/power/cleanse.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}

detect_cmd(str){
   if(!check_align()){
      tell_object(USER,
      "Your alignment robs you of your abilities!\n");
      return 1;
      }
	if(set_light(0) <= 0 && !skills[70]){ write("It is too dark.\n"); return 1; }
	if(skills[89]){ "/players/data/closed/wizard/power/detect.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}

holy_bolt_cmd(str){
   if(!check_align()){
      tell_object(USER,
      "Your alignment robs you of your abilities!\n");
      return 1;
      }
	if(set_light(0) <= 0 && !skills[70]){ write("It is too dark.\n"); return 1; }
	if(skills[93]){ "/players/data/closed/wizard/power/holy_bolt.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}

corrupt_cmd(str){
   if(!check_align()){
      tell_object(USER,
      "Your alignment robs you of your abilities!\n");
      return 1;
      }
	if(set_light(0) <= 0 && !skills[70]){ write("It is too dark.\n"); return 1; }
	if(skills[98]){ "/players/data/closed/wizard/power/corrupt.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}


redeem_cmd(str){
   if(!check_align()){
      tell_object(USER,
      "Your alignment robs you of your abilities!\n");
      return 1;
      }
	if(set_light(0) <= 0 && !skills[70]){ write("It is too dark.\n"); return 1; }
	if(skills[96]){ "/players/data/closed/wizard/power/redeem.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}

plague_cmd(str){
   if(!check_align()){
      tell_object(USER,
      "Your alignment robs you of your abilities!\n");
      return 1;
      }
	if(set_light(0) <= 0 && !skills[70]){ write("It is too dark.\n"); return 1; }
	if(skills[99]){ "/players/data/closed/wizard/power/plague.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}


sacrifice_cmd(str){
   if(!check_align()){
      tell_object(USER,
      "Your alignment robs you of your abilities!\n");
      return 1;
      }
	if(set_light(0) <= 0 && !skills[70]){ write("It is too dark.\n"); return 1; }
	if(skills[97]){ "/players/data/closed/wizard/power/sacrifice.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}







regen_aura_cmd(){
	if(USER->query_ghost()) return;
	if(!skills[92]) return;
	if(query_aura()){
		good_aura = 0;
		evil_aura = 0;
		regen_aura = 0;
		write("You concentrate and will your aura to dissipate.\n");
		return 1;
	}
	write("You concentrate...\n"+
	"A regenerative aura surrounds you in warmth.\n");
	regen_aura = 1;
	return 1;
}

prot_evil_cmd(){
	if(USER->query_ghost()) return;
	if(!skills[91]) return;
	if(query_aura()){
		good_aura = 0;
		evil_aura = 0;
		regen_aura = 0;
		write("You concentrate and will your aura to dissipate.\n");
		return 1;
	}
	write("You concentrate...\n"+
	"A protective aura surrounds you against Evil.\n");
	evil_aura = 1;
	return 1;
}

prot_good_cmd(){
	if(USER->query_ghost()) return;
	if(!skills[90]) return;
	if(query_aura()){
		good_aura = 0;
		evil_aura = 0;
		regen_aura = 0;
		write("You concentrate and will your aura to dissipate.\n");
		return 1;
	}
	write("You concentrate...\n"+
	"A protective aura surrounds you against Good.\n");
	good_aura = 1;
	return 1;
}

sacrifice_bonus(int i){
	if(!i) return sac_bonus;
	sac_bonus = i;
}
