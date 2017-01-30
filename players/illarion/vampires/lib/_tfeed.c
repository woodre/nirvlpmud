#include "../def.h"
inherit LIBBASE;

reset(arg) {
  ::reset(arg);
  requirements = ([ 
                    "ttox": ({ 0, "You cannot hold any more telepathic energy!\n" }),
                    "tox_tribute": ({ 30, "You must pay tribute in order to use this power.\n" }),
                    "not_casting": ({ "telepathy_feeding", "You cannot combine this spell.\n" }),
                    "debuff": ({ "dazed", "Your target's mental defenses have not been breached.\n" }),
                    
                  ]);
  costs = ([ 
             "ttox_heal" : 30,
             "humanity_decline" : 100,
             "debuff": ({ "dazed", 3 }),
            ]);
  skill = "Telepathy";
  combat = 1;
  heal = 1;
}

main(str, targ, usr, gob, chk) {
  int heal;
  heal = 20 + 10 * chk;
  /* consume 3 seconds of duration = 6sps = 3 fixed + 6pts of random damage */
  if(!COMDAEM->combined_spell_object(usr, gob, targ, "telepathy_feeding", 3+random(7), "other|mental",
    "You draw a small amount of energy from #TN#'s mind!\n\n",
    "#MN# gazes at you, and you feel a bit weaker!\n\n",
    "#MN# gazes at #TN#.\n#TN looks slightly weaker!\n\n"))
    return 0;

  usr->heal_self(heal); 
  return 1;
}

