#include "../defs.h"

inherit SPELL;

void reset(status arg){
  if(arg) return;
  set_spell_name("lifespring");
  set_hp_cost(0);
  set_sp_cost(0);
  set_sac_cost(0);
}

int main(string str) {
  object obj;
  
  if(str) return 0;
  
  if(!check_spell())
    return 1;
  
  if(present("druid_lifespring", environment(this_player()))) {
    write("There is already a lifespring here.\n");
    return 1;
  }
  
  else if(obj = (object)gob->query_lifespring()) {
    obj->dest_me();
  }
    
  tell_room(environment(this_player()),
"\
A trickle of "+HIW+"water"+NORM+" begins to flow from a crack in the ground.\n");

  move_object((obj=clone_object(EFFECTS+"lifespring_birth")), environment(this_player()));
  obj->set_prof((int)gob->query_prof(spell_name));
  return 1;
}
