#include <ansi.h>

int main(string str){
  object mob;
  
  if(!str) {
    if(!(mob = (object)this_player()->query_attack())){
      write("Who would you like to concentrate upon ?\n");
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
    object ob, oc;
    
    if(previous_object()->query_done()){
      write("You cannot use \"concentrate\" this round.\n");
      return 1;
    }
    
    previous_object()->set_done(1);
    
    /* cost and checks */
    
    write("You concentrate on "+(string)mob->query_name()+".\n");
    say((string)this_player()->query_name()+" concentrates on "+
      (string)mob->query_name()+".\n", mob);
    tell_object(mob, (string)this_player()->query_name()
      +" concentrates on you.\n");
      
    ob = first_inventory(environment(this_player()));
    while(ob){
      oc = next_inventory(ob);
      if(living(ob) && (object)ob->query_attack() == this_player()){
        ob->stop_fight();
        ob->stop_fight();
        this_player()->stop_fight();
        this_player()->stop_fight();
      }
      ob = oc;
    }
    
    this_player()->attack_object(mob);
  }
  return 1;
}
