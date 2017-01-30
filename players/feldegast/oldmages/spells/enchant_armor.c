#define MAGEPATH "/players/feldegast/mages/"
#include "/players/feldegast/defines.h"

inherit "/players/wocket/mages/obj/page.c";

reset(arg) {
  if(arg) return;
  spell="enchant armor";
  spell_short=HIB+"Enchant Armor"+NORM;
  spell_desc=
"  This is a relatively simple spell that prepares an armor for\n\
further enchantment.  This must be cast on an armor before another\n\
spell can be placed upon it.\n";

  time=3;
  size=5;
  spcost=50;
  hpcost=0;
  type="enchantment";
}
int check_spell(object mage, string str) {
  object target;
  target=present(str,mage);
  if(!str) {
    tell_object(mage,"The spell fizzles.\nYou must specify a target for this spell.\n");
    return 0;
  }
  if(!target) {
    tell_object(mage,"The spell fizzles.\nYou do not possess a "+str+".\n");
    return 0;
  }
  if(member_array(target->query_type(),
       ({
          "armor","shield","helmet","ring",
          "amulet","misc","boots"
       }))
     ==-1) {
    tell_object(mage,"That is not armor!\n");
    return 0;
  }
  return 1;
}
void cast_spell(object mage, string str) {
  object target;
  object shadow;
  shadow=clone_object(MAGEPATH+"obj/armor_enchantment_shadow");
  target=present(str,mage);
  if(!shadow->set_shadow(target))
    tell_object(mage,"Your spell fizzles.\n"+
                     "That item cannot be enchanted.\n");
  tell_object(mage,"You inscribe tiny runes into the "+str+", preparing it to be enchanted.\n");
  mage->remove_say(mage->query_name()+" enchants "+str+".\n");
  move_object(target,mage);
}


