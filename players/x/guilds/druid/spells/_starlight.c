#include "../defs.h"

inherit SPELL;

void reset(status arg){
  if(arg) return;
  set_spell_name("starlight");
  set_hp_cost(0);
  set_sp_cost(0);
  set_sac_cost(0);
}

int main(string str) {
  object obj;
  
  if(str) return 0;
  
  if(!check_spell())
    return 1;
  
  if(present("druid_starlight", this_player())) {
    write("The stars are already twinkling upon you.\n");
    return 1;
  }
    
  say("The "+HIM+"stars"+NORM+" in the "+HIB+"sky"+NORM+" begin to twinkle above "+
   (string)this_player()->query_name()+".\n");
  write("The "+HIM+"stars"+NORM+" in the "+HIB+"sky"+NORM+" begin to twinkle above "+
   "your head.\n");

  move_object((obj=clone_object(EFFECTS+"starlight")), this_player());
  obj->set_prof((int)gob->query_prof(spell_name));
  return 1;
}
