#include "/players/feldegast/defines.h"

inherit "/players/wocket/mages/obj/page.c";

void reset(int arg) {
  if(arg) return;
  spell="flashrune";
  spell_short="Flashrune";
  spell_desc=
"  This spell places a modified rune of protection upon a piece of\n\
armor, creating a powerful offensive charge.  The armor must first\n\
be prepared with an 'enchant armor' spell before this may be cast on\n\
it.\n";
  time=4;
  size=5;
  spcost=60;
  hpcost=0;
  type="enchantment";
}
int check_spell(object mage, string str) {
  object target;
  target=present(str,mage);
  if(!target) {
    tell_object(mage,"The spell fizzles.\nYou do not possess a "+str+".\n");
    return 0;
  }
  if(member_array(target->query_type(),
    ({
      "armor","shield","helmet","ring",
      "amulet","misc","boots",
    }))==-1) {
     tell_object(mage,"That is not armor!\n");
     return 0;
   }
   return 1;
}
void cast_spell(object mage, string str) {
  object target;
  object shadow;
  target=present(str,mage);
  shadow=(object)target->query_shadow();
  if(!shadow) {
    tell_object(mage,"Your spell fizzles.\nThat object has not yet been properly prepared.\n");
    return;
  }
  call_other(target,"add_flash",3);
  tell_object(mage,
"Your index finger glows white with heat as you chant an elaborate\n\
incantation.  You trace an elaborate glowing rune on the "+str+
"\nand seal the powerful electrical energy of a flashrune in it.\n");
  mage->remote_say((string)mage->query_name()+" enchants "+str+".\n");
}
