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
				str == "notarmor" || str == "guild_monitor";
			}
		}
	}
	
	else{
		if(offhand_name){
			return str == "guild_object" || str == "warrior_gob" || str == "prof_guild_object" ||
			str == "no_pet" || str == "no_mini" || str == "no_spell" || str == "generic_wc_bonus" ||
			str == offhand_name || str == "guild_monitor";
		}
		else{
			return str == "guild_object" || str == "warrior_gob" || str == "prof_guild_object" ||
			str == "no_pet" || str == "no_mini" || str == "no_spell" || str == "generic_wc_bonus" ||
         str == "guild_monitor";
		}
	}
	
	if(offhand_name){
		return str == "guild_object" || str == "warrior_gob" || str == "prof_guild_object" ||
		str == "no_pet" || str == "no_mini" || str == "no_spell" || str == "generic_wc_bonus" ||
		str == offhand_name || str == "guild_monitor";
	}
	else{
		return str == "guild_object" || str == "warrior_gob" || str == "prof_guild_object" ||
		str == "no_pet" || str == "no_mini" || str == "no_spell" || str == "generic_wc_bonus" ||
      str == "guild_monitor";
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
