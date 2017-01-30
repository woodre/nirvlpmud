#include "../defs.h"

inherit SPELL;

void reset(status arg){
  if(arg) return;
  set_spell_name("lifeguard");
  set_hp_cost(0);
  set_sp_cost(0);
  set_sac_cost(0);
}

int main(string str) {
  object obj;
  
  if(str) return 0;
  
  if(!check_spell())
    return 1;
    
  if(present("druid_lifeguard", this_player())) {
    write("You are already protected by a lifeguard.\n");
    return 1;
  }
    
  tell_room(environment(this_player()),
GRN+"Green light"+NORM+" briefly shimmers over "+
(string)this_player()->query_name()+"'s head.\n", ({this_player()}));
  write(GRN+"Green light"+NORM+" briefly shimmers over your head.\n");

  move_object((obj=clone_object(EFFECTS+"lifeguard")), this_player());

  obj->set_prof((int)gob->query_prof(spell_name));
  return 1;
}
