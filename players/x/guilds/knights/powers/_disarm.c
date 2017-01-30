int main(string str){
  object wep, mob;
  
  if(!str) {
    if(!(mob = (object)this_player()->query_attack())){
      write("Who would you like to disarm ?\n");
      return 1;
    }
  }
  else {
    if(!(mob = present(str, environment(this_player())))){
      write("You don't see \""+str+"\" here.\n");
      return 1;
    }
  }
  
  if(!(wep = (object)mob->query_weapon())){
    write((string)mob->query_name()+" is not wielding a weapon.\n");
  }
  
  else if(!this_player()->valid_attack(mob)) {
  }
  
  else {
    object d_obj;
    int    curr_wc, rounds;
    
    if(previous_object()->query_done()){
      write("You cannot \"disarm\" this round.\n");
      return 1;
    }
    
    previous_object()->set_done(1);
    
    if(!mob->is_player()){
      curr_wc = (int)mob->query_wc();
    }
    
    rounds = 5;
      
    d_obj = clone_object("/players/x/guilds/knights/obj/disarm_obj");
    d_obj->start_shadow(wep,curr_wc,rounds,mob);
    command("unwield "+(string)wep->query_name(), mob);
    
    /* this could do weird things ..
       ensure mob stays at current wc minus wep wc */
    if(!mob->is_player()){
      mob->set_wc(curr_wc - (int)wep->query_class());
    }
    
    write("You disarm "+(string)mob->query_name()+".\n");
    say((string)this_player()->query_name()+" disarms "
       +(string)mob->query_name()+".\n", mob);
    tell_object(mob,
        (string)this_player()->query_name()+" disarms you.\n");
  }
  return 1;
}