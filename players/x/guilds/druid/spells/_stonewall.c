#include "../defs.h"

inherit SPELL;

void reset(status arg){
  if(arg) return;
  set_spell_name("stonewall");
  set_hp_cost(0);
  set_sp_cost(0);
  set_sac_cost(0);
}

int main(string str) {
  object obj;
  
  if(str) return 0;
  
  if(!check_spell())
    return 1;
    
  if(environment(this_player())->druid_stonewall()){
    write("You are already protected by a stonewall.\n");
    return 1;
  }
  
  tell_room(environment(this_player()),
HIK+"Stone rises to protect "+(string)this_player()->query_name()+"!\n"+NORM,
 ({this_player()}));
 
  write(HIK+"Stone rises to protect you!\n"+NORM);
    
  move_object((obj=clone_object(EFFECTS+"stonewall")), environment(this_player()));
  move_object(this_player(), obj);

  obj->set_prof((int)gob->query_prof(spell_name));
  return 1;
}
