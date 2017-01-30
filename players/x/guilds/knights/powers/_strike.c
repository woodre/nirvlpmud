#include <ansi.h>

int main(string str){
  object wep, mob;
  
  if(!str) {
    if(!(mob = (object)this_player()->query_attack())){
      write("Who would you like to strike ?\n");
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
    
    if(previous_object()->query_done()){
      write("You cannot use \"strike\" this round.\n");
      return 1;
    }
    
    previous_object()->set_done(1);
    
    /* cost and checks */
    
    if(previous_object()->query_striking()){
      previous_object()->set_striking(0,0);
    }
   
    previous_object()->set_striking(1, mob);
    
    write("You start striking "+(string)mob->query_name()+".\n");
    say((string)this_player()->query_name()+" starts striking "+
      (string)mob->query_name()+".\n", mob);
    tell_object(mob, (string)this_player()->query_name()
      +" starts striking you.\n");
    
  }
  return 1;
}
