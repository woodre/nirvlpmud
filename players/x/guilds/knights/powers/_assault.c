#include <ansi.h>

int main(string str){
  object wep, mob;
  
  if(!str) {
    if(!(mob = (object)this_player()->query_attack())){
      write("Who would you like to assault ?\n");
      return 1;
    }
  }
  else {
    if(!(mob = present(str, environment(this_player())))){
      write("You don't see \""+str+"\" here.\n");
      return 1;
    }
  }
  
  if(!this_player()->valid_attack(mob)) {
  }
  
  else {
    int rage, max_rage, atks;
    
    rage =     (int)previous_object()->query_rage();
    max_rage = (int)previous_object()->query_max_rage();
    
    if(rage < 10){
      write("You are not enraged.\n");
      return 1;
    }
    
    if(previous_object()->query_done()){
      write("You cannot use \"assault\" this round.\n");
      return 1;
    }
    
    previous_object()->set_done(1);
    
    /* cost and checks */
    
    write("You assault "+(string)mob->query_name()+".\n");
    say((string)this_player()->query_name()+" assaults "+
      (string)mob->query_name()+".\n", mob);
    tell_object(mob, (string)this_player()->query_name()
      +" assaults you.\n");
    
    atks = rage / 10;
    
    previous_object()->extra_hit(atks);
    previous_object()->clear_rage(); 
  }
  return 1;
}
