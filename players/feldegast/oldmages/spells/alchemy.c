/*
Alchemy

Used to transmute base elements into gold(coins).

*/
#include "/players/feldegast/defines.h"
#define GOLD 10

inherit "/players/wocket/mages/obj/page.c";

void reset(int arg) {
  if(arg) return;
  spell="alchemy";
  spell_short="Alchemy";
  spell_desc=
"  For centuries, alchemists have sought the secret of turning\n\
base elements such as iron or copper into gold.  Much to their\n\
surprise, the answer was not to be found through the application\n\
of chemicals, but rather through magic.\n";
  time=1;
  size=4;
  spcost=50;
  hpcost=0;
  type="enchantment";
}
check_spell(object mage, string str) {
  return 1;
}
cast_spell(object mage, string str) {
  tell_object(mage,HIY+"You pick up a few rocks and stones and then squeeze them in your fists.\n"+
              "As you utter a magical incantation, you feel them changing in your hands\n"+
              "to golden coins.\n"+NORM);
  mage->remote_say(HIY+mage->query_name()+" picks up a few stones and changes them to gold.\n"+NORM);
  mage->add_money(GOLD);
}
