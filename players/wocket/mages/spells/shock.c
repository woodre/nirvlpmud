
#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/mages/obj/page.c";

object target;

reset(){
  spell = "shock";
  spell_short = BLU+"Shock"+NORM;
  spell_desc = "Magic missile ... cost 10sp";
  spcost = 15;
  hpcost = 0;
  coincost = 0;
  type = "sorcery";
  size = 2;
  time = 1;
}

check_spell(object mage,string str){
  target = previous_object()->get_target(str);
  if(!target){
    tell_object(mage,"There must be a target for this spell.\n");
    return 0;
  }
  if(!previous_object()->target_ok(target)){
    tell_object(mage,"That is not a valid target.\n");
    return 0;
  }
  return 1;
}

cast_spell(object mage){
  tell_object(mage,"You grab "+target->query_name()+" forcing "+BLU+"electricity"+NORM+" to flow through "+target->query_possessive()+" body.\n");
  tell_object(target,mage->query_name()+" grabs you forcing "+BLU+"electricity"+NORM+" to flow through your body.\n");
mage->remote_say(mage->query_name()+" grabs "+target->query_name()+" forcing "+BLU+"electricity"+NORM+" to flow through "+target->query_possessive()+" body.\n",target);
  target->attacked_by(mage);
  target->hit_player(random(40));
  return 1;

}
