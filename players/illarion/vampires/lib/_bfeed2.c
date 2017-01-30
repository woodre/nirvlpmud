#include "../def.h"
inherit LIBBASE;

reset(arg) {
  ::reset(arg);
  requirements = ([ "no_heals": ({ 0, "The mortal sustenance in your system disrupts your powers.\n" }),
                    "btox": ({ 0, "You cannot hold any more blood energy!\n" }),
                    "tox_tribute": ({ 40, "You must pay tribute in order to use this power.\n" }),
                    "not_casting": ({ "blood_feeding", "You cannot combine this spell.\n" }),
                    "debuff": ({ "bleeding", "Your target is not bleeding.\n" }),
                    "skill": ({ ({"Sanguisugency", 50 }), "Your Sanguisugency is not powerful enough.\n" }),
                  ]);
  costs = ([ 
             "btox_heal" : 40,
             "humanity_decline" : 100,
             "debuff": ({ "bleeding", 4 }),             
            ]);
  skill = "Sanguisugency";
  combat = 1;
  heal = 1;
}

main(str, targ, usr, gob, chk) {
  int heal;
  heal = 30 + 10 * chk;
  /* consume 4 seconds of duration = 8sps = 4pts fixed + 8pts of random damage */
  if(!COMDAEM->combined_spell_object(usr, gob, targ, "blood_feeding", 4+random(9), "other|blood", 
    "You pounce upon #TN# and lap up #TP# blood!\n\n",
    "#MN# pounces on you, and laps up your blood!\n\n",
    "#MN# pounces on #TN# and laps up #TP# blood!\n\n"))
    return 0;

  usr->heal_self(heal);  
  
  return 1;
}

