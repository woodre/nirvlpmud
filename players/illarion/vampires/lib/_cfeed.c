#include "../def.h"
inherit LIBBASE;

reset(arg) {
  ::reset(arg);
  requirements = ([ 
                    "ctox": ({ 0, "You cannot hold any more Corruption energy!\n" }),
                    "tox_tribute": ({ 30, "You must pay tribute in order to use this power.\n" }),
                    "not_casting": ({ "corruption_feeding", "You cannot combine these powers.\n" }),
                    "debuff": ({ "rot", "There is no poison running through their veins.\n" }),
                  ]);
  costs = ([ 
             "ctox_heal" : 30,
             "humanity_decline" : 100,
             "debuff": ({ "rot", 3 }),
            ]);
  skill = "Corruption";
  combat = 1;
  heal = 1;
}

main(str, targ, usr, gob, chk) {
  int heal;
  heal = 20 + 10 * chk;
  /* consume 3 seconds of duration = 6sps = 3 fixed + 6 random */
  if(!COMDAEM->combined_spell_object(usr, gob, targ, "corruption_feeding", 3+random(7), "other|poison",
    "You make the poison bubble in #TN#'s veins, and feed from #TP# pain and fear!\n\n",
    "The poison in your veins intensifies.  #MN# looks stronger.\n\n",
    "#TN# shivers and suffers, and #MN# looks stronger!!\n\n"))
    return 0;

  usr->heal_self(heal); 
  return 1;
}

