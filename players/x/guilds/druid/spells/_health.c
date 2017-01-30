#include "../defs.h"

inherit SPELL;

void reset(status arg){
  if(arg) return;
  set_spell_name("health");
  set_hp_cost(0);
  set_sp_cost(0);
  set_sac_cost(0);
}

int main(string str) {
  object obj;
  int my_cost;
  
  if(!str || !sscanf(str,"%d",my_cost) || my_cost < 1) {
    write("Usage: 'health <#>'\n");
    return 1;
  }
  
  set_sp_cost(my_cost);
  
  if(!check_spell())
    return 1;
 
  write("You close your eyes and draw from your mana to charge your health.\n");
  say((string)this_player()->query_name()+" closes "+possessive(this_player())
   +" eyes and looks more healthy.\n");
   
  this_player()->add_hp(my_cost * ((int)gob->query_prof(spell_name) * 100) / 10000);  
  
  return 1;
}
