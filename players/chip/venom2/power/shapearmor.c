/*
Level 1 Creation Spell: Shapearmor - Will cover parts of the body with
Dark Matter, which serves as armor of ac 1 and 4(main): 20 mp per
side piece and 40 mp for main armor.    No shield!
*/

#include "/players/chip/venom2/sdefine.h"

main(string str, object gob, object player)
{
	string type_it;
	if(USER->query_ghost()) return 0;
	if(CRE < 1) return 0;
	if(!str){ tell_object(USER, "shapearmor neckguard, cloak, boots, gloves, armor, helmet, belt, and bracers.\n"); return 1; }
	
	if(str == "all"){
      command("shapearmor neckguard", USER);
      command("shapearmor armor", USER);
      command("shapearmor boots", USER);
      command("shapearmor gloves", USER);
      command("shapearmor cloak", USER);
      command("shapearmor helmet", USER);
      command("shapearmor bracers", USER);
      command("shapearmor belt", USER);
      return 1;
      }
	if(str == "neckguard"){
		if(GOB->check_armors("amulet")){
			tell_object(USER, "You already have type Amulet worn!\n");
			return 1;
		}
		else{
			type_it = "amulet";
		}
	}
	else if(str == "cloak"){
                if(GOB->check_armors("cloak")){
                        tell_object(USER, "You already have type Cloak worn!\n");
			return 1;
		}
		else{
                        type_it = "cloak";
		}
	}
	else if(str == "boots"){
		if(GOB->check_armors("boots")){
			tell_object(USER, "You already have type Boots worn!\n");
			return 1;
		}
		else{
			type_it = "boots";
		}
	}
	else if(str == "gloves"){
		if(GOB->check_armors("gloves")){
			tell_object(USER, "You already have type Gloves worn!\n");
			return 1;
		}
		else{
                        type_it = "gloves";
		}
	}
	else if(str == "armor"){
		if(GOB->check_armors("armor")){
			tell_object(USER, "You already have type Armor worn!\n");
			return 1;
		}
		else{
			type_it = "armor";
		}
	}
	else if(str == "helmet"){
		if(GOB->check_armors("helmet")){
			tell_object(USER, "You already have type Helmet worn!\n");
			return 1;
		}
		else{
			type_it = "helmet";
		}
    }
	else if(str == "bracers"){
                if(GOB->check_armors("bracelet")){
                        tell_object(USER, "You already have type Bracelet worn!\n");
			return 1;
		}
		else{
                        type_it = "bracelet";
		}
    }
	else if(str == "belt"){
		if(GOB->check_armors("belt")){
			tell_object(USER, "You already have type Belt worn!\n");
			return 1;
		}
		else{
			type_it = "belt";
		}
	}
	else{  write("shapearmor neckguard, cloak, gloves, boots, helmet, belt, bracers, or armor.\n");
	return 1; }
	
	
	if(type_it == "armor"){
		if(GOB->query_mp() < 40){
			tell_object(USER, "You lack the "+HIK+"Dark Matter"+NORM+" to do that.\n");
			return 1;
		}
		else GOB->add_mp(-40);
	}
	else{
		if(GOB->query_mp() < 20){
			tell_object(USER, "You lack the "+HIK+"Dark Matter"+NORM+" to do that.\n");
			return 1;
		}
		else GOB->add_mp(-20);
	}
	tell_object(USER,
	"You concentrate and force your symbiote to create "+str+" from its "+HIK+"Dark Matter"+NORM+".\n");
	tell_room(environment(USER),
	BOLD+"Glistening black armor forms on "+USER->query_name()+"."+NORM+"\n");
	GOB->add_sh_armors(type_it);
	return 1;
}

