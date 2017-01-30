id(str){
	if(previous_object()){
		if(!test_my_wear(previous_object())) {
			
			if(offhand_name){
				return str == "guild_object" || str == "warrior_gob" || str == "prof_guild_object" ||
				str == "no_pet" || str == "no_mini" || str == "no_spell" || str == "generic_wc_bonus" ||
				str == offhand_name || str == "notarmor" || str == "guild_monitor";
			}
			else{
				return str == "guild_object" || str == "warrior_gob" || str == "prof_guild_object" ||
				str == "no_pet" || str == "no_mini" || str == "no_spell" || str == "generic_wc_bonus" ||
				str == "notarmor" || str == "guild_monitor" || str == "damage_report_object";
			}
		}
	}
	
	else{
		if(offhand_name){
			return str == "guild_object" || str == "warrior_gob" || str == "prof_guild_object" ||
			str == "no_pet" || str == "no_mini" || str == "no_spell" || str == "generic_wc_bonus" ||
			str == offhand_name || str == "guild_monitor" || str == "damage_report_object";
		}
		else{
			return str == "guild_object" || str == "warrior_gob" || str == "prof_guild_object" ||
			str == "no_pet" || str == "no_mini" || str == "no_spell" || str == "generic_wc_bonus" ||
         str == "guild_monitor" || str == "damage_report_object";
		}
	}
	
	if(offhand_name){
		return str == "guild_object" || str == "warrior_gob" || str == "prof_guild_object" ||
		str == "no_pet" || str == "no_mini" || str == "no_spell" || str == "generic_wc_bonus" ||
		str == offhand_name || str == "guild_monitor" || str == "damage_report_object";
	}
	else{
		return str == "guild_object" || str == "warrior_gob" || str == "prof_guild_object" ||
		str == "no_pet" || str == "no_mini" || str == "no_spell" || str == "generic_wc_bonus" ||
      str == "guild_monitor" || str == "damage_report_object";
	}
}

test_my_wear(ob){
if(!ob->query_type()) return 1;
if(ob->weapon_class()) return 1;
 if(monk){
      if(ob->query_weight() > 1){
       tell_object(USER, "This armor is too heavy!\n");  
       return 0;
       }
      }

 if(!offhand) return 1;
 if(ob->query_type() == "shield") return 0;
 return 1;
 }

report_damage(int damage, object p){
if(damage < 1) return;
if(!ATT) return;
if(!p) return;
if(!living(p)) return;

if(evil_aura){
      if(random(100) < skills[91] * 10){
		"/players/maledicta/closed/w/power/prot_evil.c"->main(this_object(), USER, damage, p);
      }
    }
if(good_aura){
      if(random(100) < skills[90] * 10){
		"/players/maledicta/closed/w/power/prot_good.c"->main(this_object(), USER, damage, p);
      }
     }
}