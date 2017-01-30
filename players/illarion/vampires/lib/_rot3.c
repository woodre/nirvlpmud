#include "../def.h"
inherit LIBBASE;

reset(arg) {
  ::reset(arg);
  requirements = ([ "sp": ({ 50, "You lack the energy.\n" }),
                    "not_casting": ({ 1, "You cannot cast another combat spell yet.\n" }),
                    "skill": ({ ({ "Corruption", 75 }), "Your Corruption is not powerful enough.\n" }),
                  ]);
  costs = ([ 
             "humanity_decline" : 100,
            ]);
  combat = 1;
  skill = "Corruption";
}

main(str, targ, usr, gob, chk) {
  int bonus;
  bonus = 5 + chk * gob->check_skill_info("level", "Corruption") / 10;

  /* use 20 sps worth of damage here = 8 fixed, 24 random */
  usr->spell_object(targ, "rot", 8+random(25), requirements["sp"][0],
    emote("You reach out and grab #TN#, stabbing poisonous nails into #TP# skin!\n\n", usr, targ),
    emote("#MN# reaches out and grabs #TN#, stabbing poisonous nails into your skin!\n\n", usr, targ),
    emote("#MN# reaches out and grabs you, stabbing poisonous nails into #TP# skin!\n\n", usr, targ));
  usr->set_spell_dtype("other|poison");
  
  /* the remaining 30sps power the debuff = 2sps/second of duration */
  COMDAEM->add_debuff(targ, "rot", bonus, 15);
  
  return 1;
}
