#include "../def.h"
inherit LIBBASE;

reset(arg) {
  ::reset(arg);
  requirements = ([ 
                    "ttox": ({ 0, "You cannot hold any more telepathic energy!\n" }),
                    "tox_tribute": ({ 50, "You must pay tribute in order to use this power.\n" }),
                    "not_casting": ({ "telepathy_feeding", "You cannot combine this spell.\n" }),
                    "debuff": ({ "dazed", "Your target's mental defenses have not been breached.\n" }),
                    "skill": ({ ({"Telepathy", 75 }), "Your Telepathy is not powerful enough.\n" }),
                  ]);
  costs = ([ 
             "ttox_heal" : 50,
             "humanity_decline" : 100,
             "debuff": ({ "dazed", 5 }),             
            ]);
  skill = "Telepathy";
  combat = 1;
  heal=1;
}

main(str, targ, usr, gob, chk) {
  int heal;
  heal = 40 + 10 * chk;
  
  /* consume 6 seconds of duration = 10sps = 5pts fixed + 10pts of random damage */
  if(!COMDAEM->combined_spell_object(usr, gob, targ, "telepathy_feeding", 5+random(11), "other|mental",
    "You draw a large amount of energy from #TN#'s mind!\n\n",
    "#MN# gazes at you, and you feel much weaker!\n\n",
    "#MN# gazes at #TN#.\n#TN looks much weaker!\n\n"))
    return 0;

  usr->heal_self(heal);  

  return 1;
}

