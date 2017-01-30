#include "/players/wocket/closed/ansi.h"
#include "/players/wocket/mages/def.h"
inherit "/players/wocket/mages/obj/page.c";

object target;

reset(){
  spell = "firebolt";
  spell_short = HIR+"Firebolt"+NORM;
  spell_desc = "Firebolt:\n\tA mighty bast of fire from the tips of the caster.\nCost: 15sp.\n";
  size = 3;
  time = 2;
  hpcost = 0;
  spcost = 15;
  coincost = 0;
  type = "sorcery";
}

check_spell(object mage,str){
  target = previous_object()->get_target(str);
  if(!target){
    tell_object(mage,"Who would you like to cast firebolt upon?\n");
    return 0;
  }
  if(!previous_object()->target_ok(target)){
    tell_object(mage,"You may not cast "+spell+" at "+str+".\n");
    return 0;
  }
  return 1;
}

cast_spell(object mage){
tell_object(mage,"You cup your hands and conjure a "+HIR+"ball of fire"+NORM+" \n"+
                 "and with a small twitch "+HIR+"fire"+NORM+" streaks through\n"+
                 "the air "+HIR+"incinerating"+NORM+" "+target->query_name()+".\n");
tell_object(target,mage->query_name()+" cups "+mage->query_possessive()+" hands and conjures a "+HIR+"ball of fire"+NORM+"\n"+
                   "and with a small twitch "+HIR+"fire"+NORM+" streaks through\n"+
                   "the air "+HIR+"incinerating"+NORM+" you.\n");
mage->remote_say(mage->query_name()+" cups "+mage->query_possessive()+" hands and conjures a "+HIR+"ball of fire"+NORM+"\n"+
                   "and with a small twitch "+HIR+"fire"+NORM+" streaks through\n"+
                   "the air "+HIR+"incinerating "+NORM+target->query_name()+".\n",target);
target->attacked_by(mage);
target->hit_player(random(40)+5);
return 1;
}
