#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/mages/obj/page.c";

object target;

reset(){
  spell = "resurrect";
  spell_short = "Resurrect";
  spell_desc = "blahbla\n";
  time = 7;
  spcost = 70;
  hpcost = 30;
  type = "necro";
  size = 7;
}

check_spell(object mage,str){
  if(!str){
    tell_object(mage,"Who would you like to cast resurrect upon?\n");
    return 0;
  }
  target= previous_object()->get_target(str);
  if(!target){
    tell_object(mage,"That player is not here to cast upon.\n");
    return 0;
  }
  if(!target->is_player()){
    tell_object(mage,"That is not a player.\n");
    return 0;
  }
  if(!target->query_ghost()){
    tell_object(mage,"That player is not dead.\n");
    return 0;
  }
  return 1;
}

cast_spell(object mage){
  tell_room(environment(mage),HIM+"Mystic flames"+NORM+" rises from the ground surrounding "+HIM+target->query_name()+".\n"+NORM);
  call_other(target,"remove_ghost",0);
  return 1;
}