#include "../defs.h"

inherit SPELL;

void reset(status arg){
  if(arg) return;
  set_spell_name("clouds");
  set_hp_cost(0);
  set_sp_cost(0);
  set_sac_cost(0);
}

int main(string str) {
  object obj;
  
  if(str) return 0;
  
  if(!check_spell())
    return 1;
    
  if(environment(this_player())->query_no_fight()){
    write("\"Clouds\" may not be cast here.\n");
    return 1;
  }
  
  if(present("druid_clouds", environment(this_player()))) {
    write("Green clouds are already obscuring the light.\n");
    return 1;
  }
    
  tell_room(environment(this_player()),
"\
"+GRN+"Green clouds"+NORM+" emerge and begin to obscure the light.\n");

  move_object((obj=clone_object(EFFECTS+"clouds")), environment(this_player()));
  obj->set_pk((int)this_player()->query_pl_k());
  obj->set_prof((int)gob->query_prof(spell_name));
  return 1;
}
