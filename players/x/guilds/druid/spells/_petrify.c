#include "../defs.h"

inherit SPELL;

void reset(status arg){
  if(arg) return;
  set_spell_name("petrify");
  set_hp_cost(0);
  set_sp_cost(0);
  set_sac_cost(0);
}

int main(string str) {
  object obj, mob;
  
  if(!str && !this_player()->query_attack()){
    write("Usage: 'petrify <monster>'\n");
    return 1;
  }
  
  if(!(mob=(object)this_player()->query_attack())){
    if(!(mob = present(str,environment(this_player())))){
      write("You don't see \""+str+"\" here.\n");
      return 1;
    }
  }
  
  if(mob->is_player()){
    write("This spell cannot be used on players.\n");
    return 1;
  }
  
  if(!check_spell())
    return 1;
  
  tell_room(environment(this_player()),
    (string)this_player()->query_name()+" points "+possessive(this_player())
    +" staff at "+(string)mob->query_name()+".\n");
  
  write("You point your staff at "+(string)mob->query_name()+".\n");
    
  move_object((obj=clone_object(EFFECTS+"petrify_birth")), mob);

  obj->set_prof((int)gob->query_prof(spell_name));
  return 1;
}
