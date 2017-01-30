#include "/players/wocket/closed/ansi.h"
#include "/players/jareel/define.h"
inherit "/obj/weapon.c";
void reset(status arg) {
  ::reset(arg);
  if(arg) return; 
  
  set_name("sword");
  set_type("sword");
  message_hit = ({
        BOLD+""+NORM+""+MAG+"ANNIHILATED"+NORM," using "+HIY+"GODLIKE PROWESS"+NORM+" with the "+HIB+"BLADE"+NORM+"!",
        BOLD+""+NORM+""+MAG+"MASSACRED"+NORM," in the head with the "+NORM+"HOLY "+HIB+"Longsword"+NORM+" +3",
        BOLD+""+NORM+""+MAG+"DECIMATED"+NORM," in the chest with a "+HIR+"MIGHTY"+NORM+" swing!",           
        BOLD+""+NORM+""+MAG+"SLASHED"+NORM," deep in the belly",
        BOLD+""+NORM+""+MAG+"STABBED"+NORM," in the stomach",
        BOLD+""+NORM+""+MAG+"CUT"+NORM," down the leg",
        BOLD+"Grazed"+NORM," on the arm with a near miss"
        });
  set_short(""+NORM+"HOLY "+HIB+"Longsword"+NORM+" +3");
  set_long("This longsword is wrapped in white cloth around its hilt. It "+HIC+"GLOWS"+NORM+"\n"+
           "lightly in your hands. It appears to be made of "+NORM+""+CYN+"mythril"+NORM+". It seems\n"+
           "to radiate a "+HIM+"holy aura"+NORM+".\n");
  set_class(18);
  set_params("other|good",0,"holy_damage");
  set_weight(3);
  set_value(50315);
  
}
query_wear() {
   return 1;
}
weapon_breaks() {
   return 1;
}
short(){
	if(wielded){
	return ""+MAG+""+wielded_by->query_name()+"'s "+NORM+"HOLY "+HIB+"Longsword"+NORM+" +3 (wielded)";
        }
	else{
 	return ""+NORM+"HOLY "+HIB+"Longsword"+NORM+" +3";
        }
       }


int holy_damage(object attacker) {
  if(!attacker || !wielded_by)
    return 0;
  if(attacker->query_alignment() < -45 && wielded_by->query_alignment() > 45) {
    tell_object(wielded_by," \n"+
                           "Your longsword "+HIC+"G L O W S "+NORM+"brightly as it "+NORM+""+RED+"S L I C E S"+NORM+" into evil.\n"+
                           " \n");
    say(" \n"+
wielded_by->query_name()+"'s longsword "+HIC+"G L O W S "+NORM+"brightly as it "+NORM+""+RED+"S L I C E S"+NORM+" into its evil prey.\n"+
                              " \n");
    attacker->hit_player(random(5), "other|good");
    return random(4);
  }
  return 0;
}

  
