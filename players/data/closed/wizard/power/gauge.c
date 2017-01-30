

#include "/players/maledicta/closed/w/sdefine.h"

main(string str, object gob, object player)
{
	string who;
	string what;
	object item;
	object peep;
	if(USER->query_ghost()) return 0;
	if(!str){ tell_object(USER, "gauge <what> -or- gauge <what> on <who>\n");
		return 1;
	}
	if(sscanf(str, "%s on %s", what, who) == 2){
		peep = present(who, environment(USER));
		if(!peep){ tell_object(USER, "They are not present!\n"); return 1; }
		item = present(what, peep);
		if(!item){ tell_object(USER, "You don't see that on "+who+".\n"); return 1; }
		if(item->armor_class() || item->weapon_class()){
			get_mess(item, player);
		}
		else{
			tell_object(USER, "You cannot gauge that!\n");
			return 1;
		}
		return 1;
	}
	else{
		item = present(str, USER);
		if(!item){ tell_object(USER, "You don't have that!\n"); return 1; }
		get_mess(item, player);
		return 1;
	}
}

get_mess(object ob, object player){
	int Wep;
	int Arm;
	int WeighIt;
	string Atype;
	string hownice;
	string itsweight;
	
   if(!ob){
		tell_object(USER, "You don't see that here.\n");
		return 1;
	}
	Wep = ob->weapon_class();
	Arm = ob->armor_class();
	Atype = ob->query_type();
	WeighIt = ob->query_weight();
	if(!Arm && !Wep){
		tell_object(USER, "This doesn't seem to be a piece of armor or a weapon.\n");
		return 1;
	}
	if(Wep){
		if(Wep > 21){
			hownice = "GrandMaster";
		}
		else if(Wep > 19){
			hownice = "Superior";
		}
		else if(Wep > 17){
			hownice = "High";
		}
		else if(Wep > 15){
			hownice = "Above Average";
		}
		else if(Wep > 12){
			hownice = "Average";
		}
		else if(Wep > 7){
			hownice = "Below Average";
		}
		else{
			hownice = "Inferior";
		}
	}
	if(Arm){
		if(Arm > 2){
			hownice = "GrandMaster";
		}
		else if(Arm > 1){
			hownice = "High";
		}
		else{
			hownice = "Average";
		}
		
		
		if(Atype == "armor"){
			if(Arm > 5){
				hownice = "GrandMaster";
			}
			else if(Arm > 4){
				hownice = "Superior";
			}
			else if(Arm > 3){
				hownice = "High";
			}
			else if(Arm > 2){
				hownice = "Average";
			}
			else if(Arm > 1){
				hownice = "Below Average";
			}
			else{
				hownice = "Inferior";
			}
		}
	}
	if(WeighIt > 6){
		itsweight = "a Lead weight";
	}
	else if(WeighIt > 4){
		itsweight = "Very Heavy";
	}
	else if(WeighIt > 2){
		itsweight = "Heavy";
	}
	else if(WeighIt > 1){
		itsweight = "of Average Weight";
	}
	else{
		itsweight = "Very Light";
	}
	
	
	tell_object(USER, "You study the "+capitalize(ob->query_name())+" carefully...\n"+
	"It appears to be of "+hownice+" quality, and is "+itsweight+".\n");
	if(ob->query_hit_func()){
		tell_object(USER, "It seems to possess some Other power. Although you cannot\n"+
		"judge what without using it.\n");
	}
	if(ob->query_type()){
		tell_object(USER, "It seems to be of '"+ob->query_type()+"' type.\n");
	}
	if(ob->query_save_flag()){
		tell_object(USER, "The "+ob->query_name()+" is not saveable.\n");
	}
      tell_object(USER, ob->query_name()+" is worth "+ob->query_value()+" coins.\n");
	return 1;
}
