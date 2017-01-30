#include "/players/feldegast/defines.h"

inherit "/players/wocket/mages/obj/page.c";

  object targ;
  
void reset(int arg) {
  if(arg) return;
  spell="cache";
  spell_short="Cache";
  spell_desc=
"  Since time immemorial, magicians and sorcerors have sought to\n\
enhance their magical strength.  Most have sought to do this through\n\
meditation, practice, or pacts with denizens of the lower realms.\n\
While not quite as effective as those methods, many enchanters have\n\
found it easier and less deletorious to their free time to simply\n\
place some of their energy in a prepared object for later reuse.\n";
  time=2;
  size=3;
  spcost=40;
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
  if(!target->query_shadow()) {
    tell_object(mage,"The spell fizzles.\nThat object has not yet been properly prepared.\n");
    return 0;
  }
  return 1;
}
void cast_spell(object mage, string str) {
  object shadow;
  int ammount;
  targ=present(str,mage);
  shadow=(object)targ->query_shadow();
  ammount=10+random(20);
  call_other(shadow,"add_energy",ammount);
  tell_object(mage,
"You cache "+ammount+" sps into the "+str+".\n");
  mage->remote_say((string)mage->query_name()+" enchants "+str+".\n");
}
