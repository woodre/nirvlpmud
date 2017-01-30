#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/mages/obj/page.c";

object target;

reset(){
  spell = "magic missile";
  spell_short = GRN+"Magic Missile"+NORM;
  spell_desc = "Magic missile ... cost 10sp";
  spcost = 10;
  hpcost = 0;
  coincost = 0;
  type = "sor";
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
  tell_object(mage,"You hurl a "+GRN+spell+OFF+" at "+target->query_name()+".\n");
  tell_object(target,mage->query_name()+" hurls a "+GRN+spell+OFF+" at you.\n");
  mage->remote_say(mage->query_name()+" hurls a "+GRN+spell+OFF+" at "+target->query_name()+".\n",target);
  target->attacked_by(mage);
  target->hit_player(random(30));
  return 1;

}
