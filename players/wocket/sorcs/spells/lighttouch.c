#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/mages/obj/page.c";

reset(){
  spell = "lighttouch";
  spell_short = HIR+"lighttouch"+NORM;
  time = 1;
  size = 1;
  hpcost = 0;
  spcost = 15;
   type = "sorcery";
}

cast_spell(object mage, str){
object target;
target = previous_object()->get_target(str);
if(!target){
  tell_object(mage,"You spell fizzles.\n");
  return;
}
tell_object(mage,"Your hands glow a cooling "+HIC+"blue"+NORM+".\n");
tell_object(mage,"You touch "+target->query_name()+" very lightly, healing them some.\n");
tell_object(target,mage->query_name()+" touches you very lightly, healing you some.\n");
mage->remote_say(mage->query_name()+" lightly touches "+target->query_name()+", healing them.\n",target);
target->add_hit_point(5+random(20));
}
