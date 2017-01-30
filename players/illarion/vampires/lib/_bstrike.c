#include "../def.h"
inherit LIBBASE;

reset(arg) {
  ::reset(arg);
  requirements = ([ 
                    "sp": ({ 20, "You lack the energy.\n" }),
                    "not_casting": ({ 1, "You cannot cast another combat spell yet.\n" }),
                    "ttox": ({ 2, "You do not have enough Telepathic energy.\n" }),
                    "tribute": ({ 20, "You must pay tribute in order to use this power.\n" }),
                    "skill": ({ ({"Telepathy", 50 }), "Your Telepathy is not powerful enough.\n" }),
                  ]);
  costs = ([ 
             "ttox": -2,
             "tribute": -20,
            ]);
  combat = 1;
  skill = "Fortitude";
}

main(str, targ, usr, gob, chk) {
  int dam;
  object wep;
  dam = 30 + (10 * chk); 
  if((wep = usr->query_wielded()))
    dam+=wep->hit(targ);
  
  usr->spell_object(targ, "bstrike", 1+random(dam), requirements["sp"][0],
    emote("You briefly overcome #TN#'s mind, allowing yourself a free strike!\n\n", usr, targ),
    emote("#MN# rolls your mind, and gets in a free strike!\n\n", usr, targ),
    emote("#TN# just stands there and takes a free strike from #MN#!\n\n", usr, targ));
  usr->set_spell_dtype("other|evil");
    
  return 1;
}
