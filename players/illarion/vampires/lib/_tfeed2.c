#include "../def.h"
inherit LIBBASE;

reset(arg) {
  ::reset(arg);
  requirements = ([ 
                    "ttox": ({ 0, "You cannot hold any more telepathic energy!\n" }),
                    "tox_tribute": ({ 40, "You must pay tribute in order to use this power.\n" }),
                    "not_casting": ({ "telepathy_feeding", "You cannot combine this spell.\n" }),
                    "debuff": ({ "dazed", "Your target's mental defenses have not been breached.\n" }),
                    "skill": ({ ({"Telepathy", 50 }), "Your Telepathy is not powerful enough.\n" }),
                  ]);
  costs = ([ 
             "ttox_heal" : 40,
             "humanity_decline" : 100,
             "debuff": ({ "dazed", 4 }),
            ]);
  skill = "Telepathy";
  combat = 1;
  heal = 1;
}

main(str, targ, usr, gob, chk) {
  int heal;
  heal = 30 + 10 * chk;
  
  /* consume 4 seconds of duration = 8sps = 4pts fixed + 8pts of random damage */
  if(!COMDAEM->combined_spell_object(usr, gob, targ, "telepathy_feeding", 4+random(9), "other|mental", 
    "You draw a moderate amount of energy from #TN#'s mind!\n\n",
    "#MN# gazes at you, and you feel moderately weaker!\n\n",
    "#MN# gazes at #TN#.\n#TN looks moderately weaker!\n\n"))
    return 0;

  usr->heal_self(heal);  
  
  return 1;
}

