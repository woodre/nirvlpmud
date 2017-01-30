id(str){
	if(previous_object()){
		if(!test_my_wear(previous_object())) {
			
			if(offhand_name){
				return str == "guild_object" || str == "warrior_gob" || str == "prof_guild_object" ||
				str == "no_pet" || str == "no_mini" || str == "no_spell" || str == "generic_wc_bonus" ||
				str == offhand_name || str == "notarmor";
			}
			else{
				return str == "guild_object" || str == "warrior_gob" || str == "prof_guild_object" ||
				str == "no_pet" || str == "no_mini" || str == "no_spell" || str == "generic_wc_bonus" ||
				str == "notarmor";
			}
		}
	}
	
	else{
		if(offhand_name){
			return str == "guild_object" || str == "warrior_gob" || str == "prof_guild_object" ||
			str == "no_pet" || str == "no_mini" || str == "no_spell" || str == "generic_wc_bonus" ||
			str == offhand_name;
		}
		else{
			return str == "guild_object" || str == "warrior_gob" || str == "prof_guild_object" ||
			str == "no_pet" || str == "no_mini" || str == "no_spell" || str == "generic_wc_bonus";
		}
	}
	
	if(offhand_name){
		return str == "guild_object" || str == "warrior_gob" || str == "prof_guild_object" ||
		str == "no_pet" || str == "no_mini" || str == "no_spell" || str == "generic_wc_bonus" ||
		str == offhand_name;
	}
	else{
		return str == "guild_object" || str == "warrior_gob" || str == "prof_guild_object" ||
		str == "no_pet" || str == "no_mini" || str == "no_spell" || str == "generic_wc_bonus";
	}
}

test_my_wear(ob){
 if(!offhand) return 1;
 if(ob->query_type() == "shield") return 0;
 return 1;
 }
