#include "../def.h"
inherit LIBBASE;

reset(arg) {
  ::reset(arg);
  requirements = ([ "sp": ({ 30, "You lack the energy.\n" }),
                    "not_casting": ({ 1, "You cannot cast another combat spell yet.\n" }),
                  ]);
  costs = ([ 
             "humanity_decline" : 100,
             "sp" : 30
            ]);
  combat = 1;
  skill = "Sanguisugency";
}

main(str, targ, usr, gob, chk) {
  int bonus;
  bonus = 5 + chk * 5;
  /* use 10 sps worth of damage here = 4 fixed, 12 random */
  usr->spell_object(targ, "scratch", 4+random(13), requirements["sp"][0],
    emote("You reach out with your $HW$TALONED CLAWS$N$ and $HW$RAKE$N$ #TN#!\n\n", usr, targ),
    emote("#MN# reaches out with #MP# $HW$TALONED CLAWS$N$ and $HW$RAKES$N$ you!\n\n", usr, targ),
    emote("#MN# reaches out with #MP# $HW$TALONED CLAWS$N$ and $HW$RAKES$N$ #TN#!\n\n", usr, targ));
  usr->set_spell_dtype("other|blood");
  /* The remaining 20 sps charge the debuff = each second of the duration is worth 2sps */
  /* this will either cause 2 fixed 4 random damage every round, OR be consumed by bfeed spells */
  COMDAEM->add_debuff(targ, "bleeding", 4, 10);
  
  return 1;
}
