#include "../defs.h"

inherit SPELL;

void reset(status arg){
  if(arg) return;
  set_spell_name("summon elemental");
  set_hp_cost(0);
  set_sp_cost(0);
  set_sac_cost(0);
}

int main(string str) {
  object obj;
  
  if(!str || str != "elemental")
    return 0;
  
  if(!check_spell())
    return 1;
  /*  
  if(environment(this_player())->query_no_fight())
  */
  
  if(gob->query_pet()) {
    write("You already have an elemental summoned.\n");
    return 1;
  }
    
  tell_room(environment(this_player()),
(string)this_player()->query_name()+"'s staff glows "+HIG+"bright green"+NORM+".\n",
  ({this_player()}));
  write("Your staff glows "+HIG+"bright green"+NORM+".\n");

  move_object((obj=clone_object(EFFECTS+"elemental_birth")), environment(this_player()));
  obj->set_prof((int)gob->query_prof(spell_name));
  return 1;
}
