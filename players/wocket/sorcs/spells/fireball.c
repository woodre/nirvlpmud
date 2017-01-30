
#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/mages/obj/page.c";

object target;

reset(){
  spell = "fireball";
  spell_short = RED+"Fireball"+NORM;
  spell_desc = "Fireball ... cost 20 sp. \n";
  spcost = 20;
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
  tell_object(mage,"something something fireball somethin something.\n");
  tell_object(target,mage->query_name()+" grabs you forcing "+BLU+"electricity"+NORM+" to flow through your body.\n");
mage->remote_say(mage->query_name()+" grabs "+target->query_name()+" forcing "+BLU+"electricity"+NORM+" to flow through "+target->query_possessive()+" body.\n",target);
  target->attacked_by(mage);
  mage->attacked_by(target);
  target->hit_player(random(40));
  return 1;

}
