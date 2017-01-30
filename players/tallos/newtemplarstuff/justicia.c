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
  set_short("Justicia: The Sword of the Knights Templar");
  set_long("           _/\\_                                                \n"+
           "          / -- \\                                               \n"+
           "          | || |                                               \n"+
           "          | || |                                               \n"+
           "          | || |          Justicia: The Sword of               \n"+
           "          | || |          The Knights Templar                  \n"+
           "          | || |                                               \n"+
           "          | || |              Justicia is 46 inches long, and  \n"+
           "          | || |          adorned with silver medallions on    \n"+
           "          | || |          a gold plated hilt. It is accented   \n"+
           "          | || |          with enameled red crosses, and from  \n"+
           "          | || |          its pomme extends a finely honed     \n"+
           "          | || |          420 stainless steel blade. Justicia, \n"+ 
           "          | || |          latin for Justice, is an extremely   \n"+
           "    ______|_--_|______    attractive piece of medieveal        \n"+
           "   /_______    _______\\   weaponry and coveted by The Knights   \n"+
           "   \\_______    _______/   Templar as their holy instrument of   \n"+
           "         \\      /         justice...                           \n"+
           "          |====|                                               \n"+
           "          |====|                                               \n"+
           "          |====|                                               \n"+
           "          |====|                                               \n"+
           "          |====|                                               \n"+
           "          \\====/                                               \n"+
           "          /____\\                                               \n"+
           "           ====                                                \n");
  set_class(20);
  set_params("other|good",0,"holy_smite");
  set_weight(4);
  set_value(0);
  
}


int holy_smite(object attacker) {
  if(!attacker || !wielded_by)
    return 0;
  if(attacker->query_alignment() < -45 && wielded_by->query_alignment() > 45)  {
	  if(call_other(this_player(),"query_attrib","pie") > random(150)) {
    
	  tell_object(wielded_by," \n"+
                           "Your longsword "+HIC+"G L O W S "+NORM+"brightly as it "+NORM+""+RED+"S L I C E S"+NORM+" into evil.\n"+
                           " \n");
    say(" \n"+
wielded_by->query_name()+"'s longsword "+HIC+"G L O W S "+NORM+"brightly as it "+NORM+""+RED+"S L I C E S"+NORM+" into its evil prey.\n"+
                              " \n");
    attacker->hit_player(10 + random(60), "other|good");
    return 1;
  }
    return 1;
}
  return 0;
}

  
