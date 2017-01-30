#include "../def.h"
inherit LIBBASE;

reset(arg) {
  ::reset(arg);
  requirements = ([ 
                    "sp": ({ 20, "You lack the energy.\n" }),
                    "not_casting": ({ 1, "You cannot cast another combat spell yet.\n" }),
                    "btox": ({ 2, "You do not have enough blood energy.\n" }),
                    "tribute": ({ 20, "You must pay tribute in order to use this power.\n" }),
                  ]);
  costs = ([ 
             "humanity_decline" : 100,
             "btox": -2,
             "tribute": -20,
            ]);
  combat = 1;
  skill = "Fortitude";
}

main(str, targ, usr, gob, chk) {
  int dam;
  dam = 15 + (5 * chk); /* 5 on success, 10 on crit success, 0 on fail, -5 on crit fail */
  
  usr->spell_object(targ, "backhand", 1+random(dam), requirements["sp"][0],
    emote("You backhand #TN# across the face!\n\n", usr, targ),
    emote("#MN# backhands you across the face!\n\n", usr, targ),
    emote("#MN# backhands #TN# across the face!\n\n", usr, targ));
  usr->set_spell_dtype("other|evil");
    
  return 1;
}
