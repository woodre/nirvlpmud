#include "../def.h"
inherit LIBBASE;

reset(arg) {
  ::reset(arg);
  requirements = ([ "no_heals": ({ 0, "The mortal sustenance in your system disrupts your powers.\n" }),
                    "ctox": ({ 0, "You cannot hold any more Corruption energy!\n" }),
                    "tox_tribute": ({ 40, "You must pay tribute in order to use this power.\n" }),
                    "not_casting": ({ "corruption_feeding", "You cannot combine these powers.\n" }),
                    "debuff": ({ "rot", "There is no poison running through their veins.\n" }),
                    "skill": ({ ({ "Corruption", 50 }), "Your Corruption is not powerful enough.\n" }),
                  ]);
  costs = ([ 
             "ctox_heal" : 40,
             "humanity_decline" : 100,
             "debuff": ({ "rot", 4 }),
            ]);
  skill = "Corruption";            
  combat = 1;
  heal = 1;
}

main(str, targ, usr, gob, chk) {
  int heal;
  heal = 30 + 10 * chk;
  /* consume 4 seconds of duration = 8sps = 4pts fixed + 8pts of random damage */  
  if(!COMDAEM->combined_spell_object(usr, gob, targ, "corruption_feeding", 4+random(9), "other|poison",
    "You make the poison bubble in #TN#'s veins, and feed from #TP# pain and fear!\n\n",
    "The poison in your veins intensifies.  #MN# looks stronger.\n\n",
    "#TN# shivers and suffers, and #MN# looks stronger!!\n\n"))
    return 0;

  usr->heal_self(heal);  
  return 1;
}

