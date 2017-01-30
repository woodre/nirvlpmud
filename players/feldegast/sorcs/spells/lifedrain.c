#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/mages/obj/page.c";

object target;

reset(){
  spell = "lifedrain";
  spell_short = HIM+"Lifedrain"+NORM;
  spell_desc = "Lifedrain: \nblah blah drains life blah blah\nCost: 50 sp\n";
  size = 1;
  time = 3;
  type = "necro";
  spcost = 50;
  hpcost = 0;
}

check_spell(object mage,str){
target = previous_object()->get_target(str);
if(!target){
tell_object(mage,"What would you like to cast lifedrain upon?\n");
return;
}
if(!previous_object()->target_ok(target)){
  tell_object(mage,"You may not cast lifedrain upon "+str+".\n");
  return;
}
return 1;
}


cast_spell(mage){
int heal;
tell_object(mage,"You reach for "+target->query_name()+" fiercely.\n"+
                 "As you touch "+target->query_objective()+GRN+" a dark myst flows"+NORM+"\n"+
                 "draining life that becomes your own.\n");
tell_object(target,mage->query_name()+" reaches for you.\n"+
                   "As "+mage->query_objective()+" touches you "+GRN+"a dark myst flows\n"+NORM+
                   "draining life that becomes "+mage->query_objective()+" own.\n");
mage->remote_say(mage->query_name()+" reaches for "+target->query_name()+".\n"+
                   GRN+"A dark myst flows "+NORM+"between them.\n",target);
heal = random(15)+random(30)+10;
target->attacked_by(mage);
target->hit_player(heal);
mage->add_hit_point(heal);
}
