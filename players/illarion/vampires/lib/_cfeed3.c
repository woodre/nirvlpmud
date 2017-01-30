#include "../def.h"
inherit LIBBASE;

reset(arg) {
  ::reset(arg);
  requirements = ([ "no_heals": ({ 0, "The mortal sustenance in your system disrupts your powers.\n" }),
                    "ctox": ({ 0, "You cannot hold any more Corruption energy!\n" }),
                    "tox_tribute": ({ 50, "You must pay tribute in order to use this power.\n" }),
                    "not_casting": ({ "corruption_feeding", "You cannot combine these powers.\n" }),
                    "debuff": ({ "rot", "There is no poison running through their veins.\n" }),
                    "skill": ({ ({ "Corruption", 75 }), "Your Corruption is not powerful enough.\n" }),
                  ]);
  costs = ([ 
             "ctox_heal" : 50,
             "humanity_decline" : 100,
             "debuff": ({ "rot", 5 }),             
            ]);
  skill = "Corruption";            
  combat = 1;
  heal = 1;
}

main(str, targ, usr, gob, chk) {
  int heal;
  heal = 40 + 10 * chk;
  /* consume 5 seconds of duration = 10sps = 5pits fixed + 10pts of random damage */
  if(!COMDAEM->combined_spell_object(usr, gob, targ, "corruption_feeding", 5+random(11), "other|poison",
    "You make the poison bubble in #TN#'s veins, and feed from #TP# pain and fear!\n\n",
    "The poison in your veins intensifies.  #MN# looks stronger.\n\n",
    "#TN# shivers and suffers, and #TN# looks stronger!!\n\n"))
    return 0;

  usr->heal_self(heal);  
  return 1;
}

