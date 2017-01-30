/* i fixed the inherit/include order but this is still borken on LD - miz */
inherit "/players/wocket/mages/obj/page.c";
#include "/players/wocket/closed/ansi.h"

object mage,target;
reset(){
  spell = "freezing touch";
  spell_short = HIC+"Freezing Touch"+NORM;
  spell_desc = "Icetouch:\n\tA touch of cold which damages an opponent.\nCost: 10hp 30sp\n";
  size = 2;
  time = 2;
  hpcost = 10;
  spcost = 30;
  type = "sorcery";
}

check_spell(object mage,str){
target = previous_object()->get_target(str);
if(!target){
  tell_object(mage,"What would you like to cast freezing touch upon?");
  return;
}
if(!previous_object()->target_ok(target)){
  tell_object(mage,"You may not cast freezing touch at "+str+".\n");
  spell_failure(mage);
  return;
}
return 1;
}

cast_spell(mage){
tell_object(mage,"Ice "+HIC+"sparkles"+NORM+" upon your finger tips as you touch "+target->query_name()+".\n"+
                 capitalize(target->query_possessive())+" body begins to "+HIC+"FREEZE"+NORM+" as "+target->query_pronoun()+" riles in pain.\n"+
                 "Frostbite takes hold of your fingers.\n");

target->attacked_by(mage);
target->hit_player(random(90));
}
