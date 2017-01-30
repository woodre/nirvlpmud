#include "/players/wocket/closed/ansi.h"
#include "../def.h"
inherit "/players/wocket/mages/obj/page.c";
object target;

reset(arg){
  spell = "invisibility";
  spell_short = "Invisibility";
  spell_desc = "Turn invisible.. doh.\n";
  type = "ill";
  spcost = 35;
  hpcost = 0;
  coincost = 0;
  size = 3;
  time = 3;
}

check_spell(object mage,str){
if(!str)
  target = mage;
else
target = previous_object()->get_target(str);
if(!target->is_player()){
  write("You may not cast invisibility upon non-players.\n");
  return 0;
}
return 1;
}

cast_spell(object mage){
  tell_object(target,HIC+"You see yourself slowly vanish.\n"+OFF);
  target->remote_say(HIC+"You see "+target->query_name()+" slowly vanish.\n"+OFF);
  target->set_invs_sp();
  return 1;
}
