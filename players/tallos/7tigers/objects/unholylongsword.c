#include "/players/wocket/closed/ansi.h"
inherit "/obj/weapon.c";

void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  
  set_name("sword");
  set_type("sword");
    message_hit = ({
        BOLD+""+NORM+""+HIR+"ANNIHILATED"+NORM," using "+NORM+""+RED+"DEMONIC PROWESS"+NORM+" with the "+HIB+"BLADE"+NORM+"!",
        BOLD+""+NORM+""+HIR+"MASSACRED"+NORM," in the head with the "+NORM+""+RED+"UNHOLY "+HIB+"Longsword"+NORM+" +3",
        BOLD+""+NORM+""+HIR+"DECIMATED"+NORM," in the chest with a "+HIR+"DEADLY"+NORM+" swing!",           
        BOLD+""+NORM+""+HIR+"SLASHED"+NORM," deep in the belly",
        BOLD+""+NORM+""+HIR+"STABBED"+NORM," in the stomach",
        BOLD+""+NORM+""+HIR+"CUT"+NORM," down the leg",
        BOLD+"Grazed"+NORM," on the arm with a near miss"
        });
  set_short(""+RED+"UNHOLY "+HIB+"Longsword"+NORM+" +3");
  set_long("This "+HIB+"longsword"+NORM+" is wrapped in "+HIR+"red cloth"+NORM+" around its hilt. It "+HIR+"G"+NORM+""+RED+"L"+HIR+"O"+NORM+""+RED+"W"+HIR+"S\n"+
           "demonically"+NORM+" in your hands. It appears to be made of "+NORM+""+CYN+"dark steel"+NORM+". The\n"+
           ""+HIB+"sword"+NORM+" radiates an "+RED+"unholy aura"+NORM+".\n");
  set_class(19);
  set_params("other|evil",0,"unholy_damage");
  set_weight(4);
  set_value(7000);
}
short(){
	if(wielded){
	return ""+HIR+""+wielded_by->query_name()+"'s "+NORM+""+RED+"UNHOLY "+HIB+"Longsword"+NORM+" +3 (wielded)";
        }
	else{
 	return ""+RED+"UNHOLY "+HIB+"Longsword"+NORM+" +3";
        }
       }


int unholy_damage(object attacker){
  if(attacker->query_alignment() > -45 && wielded_by->query_alignment() < 45) {
    tell_object(wielded_by," \n"+
                           "Your longsword "+HIR+"G L O W S "+NORM+""+RED+"demonically"+NORM+" as it "+HIB+"C L E A V E S"+NORM+" into its prey.\n"+
                           " \n");
    say(" \n"+
wielded_by->query_name()+"'s longsword "+HIR+"G L O W S "+NORM+""+RED+"demonically"+NORM+" as it "+HIB+"C L E A V E S"+NORM+" into its prey.\n"+
                              " \n");
    attacker->hit_player(random(5), "other|evil");
    return random(4);
  }
  return 0;
} 
