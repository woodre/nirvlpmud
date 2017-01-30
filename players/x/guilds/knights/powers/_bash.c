#include <ansi.h>

int main(string str){
  object wep, mob;
  
  if(!str) {
    if(!(mob = (object)this_player()->query_attack())){
      write("Who would you like to bash ?\n");
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
    object ob, next, shield;
    
    ob = first_inventory(this_player());
    while(ob && !shield){
      next = next_inventory(ob);
      if(ob->is_armor() && (string)ob->query_type()=="shield" &&
         ob->query_worn()){
        shield = ob;
      }
      else {
        ob = next;
      }
    }
    if(!shield){
      write("You are not wearing a shield.\n");
      return 1;
    }
    
    if(previous_object()->query_done()){
      write("You cannot perform \"bash\" this round.\n");
      return 1;
    }
    
    previous_object()->set_done(1);
    
    /* cost and checks */
    
    write("You shield-bash "+(string)mob->query_name()+".\n");
    say((string)this_player()->query_name()+" shield-bashes "+
      (string)mob->query_name()+".\n", mob);
    tell_object(mob, (string)this_player()->query_name()
      +" shield-bashes you.\n");
    
    mob->hit_player((int)shield->query_ac()*10+10); 
    
    /* if high enough proficiency */
    
    if(!mob->is_player()){
      
      if(mob->is_bash_reeling()){
        mob->end_bash();
      }
    
      ob = clone_object("/players/x/guilds/knights/obj/bash_shadow");
      ob->start_bash(mob, 30); /* 2nd arg is time */
      tell_room(environment(mob),
        (string)mob->query_name()+" "+HIK+"REELS"+NORM
        +" from the blow!\n", ({mob}));
      tell_object(mob,
       "You "+HIK+"REEL"+NORM+" from the blow!\n");
    } 
  }
  return 1;
}