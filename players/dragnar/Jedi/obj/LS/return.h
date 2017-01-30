return_saber(string str){
  if(!JEDI){ return 0; }	
  if(!str){ tell_object(USER, "Latch what?\n"); return 1; }
  if(!wep_life){ tell_object(USER,
     "It's lack of power makes it useless.\n");
     return 1; 
  }
  if(wielded || ignited)  command("collapse saber",USER);
  if(ignited || wielded){
    tell_object(USER,
    "You must collapse it first.\n");
    return 1; 
  }
   
  tell_object(USER,
    "You latch your lightsaber to your belt and hide it from sight.\n");  	  	     
  say(capitalize(this_player()->query_name())+" latches "+this_player()->query_possessive()+" lightsaber to "+this_player()->query_possessive()+" belt.\n");
  JEDI->set_wep_life(wep_life);
  JEDI->set_wep_color(Color);
  JEDI->save_stats();
  destruct(this_object());     
  return 1;
}	
