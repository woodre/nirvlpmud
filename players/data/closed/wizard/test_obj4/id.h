id(str){
	if(previous_object()){
		if(!test_my_wear(previous_object())) {
			
			if(offhand_name){
				return str == "guild_object" || str == "warrior_gob" || str == "prof_guild_object" ||
				str == "no_pet" || str == "no_mini" || str == "no_spell" || str == "generic_wc_bonus" ||
				str == offhand_name || str == "notarmor" || str == "guild_monitor"||str=="GI";
			}
			else{
				return str == "guild_object" || str == "warrior_gob" || str == "prof_guild_object" ||
				str == "no_pet" || str == "no_mini" || str == "no_spell" || str == "generic_wc_bonus" ||
				str == "notarmor" || str == "guild_monitor" || str == "damage_report_object" || str=="GI";
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
 if(berserker){
 if(ob->query_type() == "armor"){
   tell_object(USER, "This armor would interfere with your abilities.\n");
   return 0;
   }
 if(ob->query_type() == "helmet"){
   tell_object(USER, "This armor would interfere with your abilities.\n");
   return 0;
   }
 if(ob->query_type() == "underwear"){
   tell_object(USER, "This armor would interfere with your abilities.\n");
   return 0;
   }
 }
 if(knight){
   if(ob->query_type() == "armor" && !no_knight(ob)){
   tell_object(USER, "This armor is beneath your station.\n");
   return 0;
   }
   if(ob->query_type() == "ring" && ob->query_value() < 1000){
   tell_object(USER, "This armor is beneath your station.\n");
   return 0;
   }
   if(ob->query_type() == "helmet" && ob->query_value() < 1000){
   tell_object(USER, "This armor is beneath your station.\n");
   return 0;
   } 
   if(ob->query_type() == "boots" && ob->query_value() < 1000){
   tell_object(USER, "This armor is beneath your station.\n");
   return 0;
   }
   if(ob->query_type() == "misc" && ob->query_value() < 1000){
   tell_object(USER, "This armor is beneath your station.\n");
   return 0;
   }
   if(ob->query_type() == "amulet" && ob->query_value() < 1000){
   tell_object(USER, "This armor is beneath your station.\n");
   return 0;
   }
   if(ob->query_type() == "armor" && ob->query_value() < 3500){
   tell_object(USER, "This armor is beneath your station.\n");
   return 0;
   }
   if(ob->query_type() == "shield" && ob->query_value() < 1000){
   tell_object(USER, "This armor is beneath your station.\n");
   return 0;
   }
   }
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

no_knight(object ob){
if(call_other(ob,"id", "habit") || call_other(ob, "id", "robe") ||
   call_other(ob, "id", "veil") || call_other(ob, "id", "robes") ||
   call_other(ob, "id", "cloak") || call_other(ob, "id", "tunic") ||
   call_other(ob, "id", "cape") || call_other(ob, "id", "wings") ||
   call_other(ob, "id", "duster") || call_other(ob, "id", "vest") ||
   call_other(ob, "id", "coat") || call_other(ob, "id", "shirt") ||
   call_other(ob, "id", "hide") || call_other(ob, "id", "skin"))
   return 0;
else return 1;
}


report_damage(int damage, object p){
int nzerk;
if(damage < 1) return;
if(!ATT) return;
if(!p) return;
if(!living(p)) return;
if(berserker && skills[124] && random(100) < skills[124] * 8){
 if(endurance > 8){
  if(damage > 199)      nzerk = 90;
  else if(damage > 150) nzerk = 50;
  else if(damage > 125) nzerk = 40;
  else if(damage > 110) nzerk = 35;
  else if(damage > 90)  nzerk = 25;
  else if(damage > 70)  nzerk = 20;
  else if(damage > 60)  nzerk = 15;
  else if(damage > 50)  nzerk = 10;
  else if(damage > 45)  nzerk = 8;
  else if(damage > 40)  nzerk = 6;
  else if(damage > 30)  nzerk = 3;
  if(nzerk > zerk) zerk = nzerk;
  add_end(-8);
  }   
 }
if(evil_aura){
      if(random(100) < skills[91] * 15){
		"/players/maledicta/closed/w/power/prot_evil.c"->main(this_object(), USER, damage, p);
      }
    }
if(good_aura){
      if(random(100) < skills[90] * 15){
		"/players/maledicta/closed/w/power/prot_good.c"->main(this_object(), USER, damage, p);
      }
     }
}
