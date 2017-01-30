#include "../def.h"
inherit LIBBASE;

reset(arg) {
  ::reset(arg);
  requirements = ([ "sp": ({ 30, "You lack the energy.\n" }),
                    "not_casting": ({ 1, "You cannot cast another combat spell yet.\n" }),
                  ]);
  costs = ([ 
             "humanity_decline" : 100,
            ]);
  combat = 1;
  skill = "Telepathy";
}

main(str, targ, usr, gob, chk) {
  int bonus;
  bonus = 5 + chk * gob->check_skill_info("level", "Telepathy") / 10;

  /* use 10 sp here for a minor amount of damage */
  usr->spell_object(targ, "daze", 4+random(13), requirements["sp"][0],
    emote("You capture #TN#'s gaze and STAB into #TP# psyche.\n\n", usr, targ),
    emote("#MN# captures #TN#'s gaze.  #TN# shudders violently.\n\n", usr, targ),
    emote("#MN# captures your gaze and STABS into your psyche.\n\n", usr, targ));
  usr->set_spell_dtype("other|mental");
  
  /* the remaining 20 sp goes into the debuff duration: 1 second = 2sps */
  COMDAEM->add_debuff(targ, "dazed", bonus, 10);
  
  return 1;
}
