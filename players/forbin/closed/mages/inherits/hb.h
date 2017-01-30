heart_beat() {
  if(!environment()) 
    return ;
  if(!environment(this_object())->is_player())
    return ;
  if(!environment(this_object())->query_interactive())
    return ;

  HBeats++;
  
  if(OldXp < 1) OldXp = environment(this_object())->query_exp();     /* Deal with exp gain */
  
  if((OldXp + 8) < environment(this_object())->query_exp()) {        /* +8 for small adds */
    int gain, amount;
    gain = environment(this_object())->query_exp() - OldXp;
    amount = 0;
    if(SchoolsXP < 4500000) {                                        /* 15% to magic schools */
      SchoolsXP += ((15 * gain) / 100);
      amount += 15;
      check_schools();
    }    
    if(AttribsXP < 2000000) {                                        /* 10% to guild attributes */
      AttribsXP += ((10 * gain) / 100);
      amount += 10;
      check_attributes();
    }
    environment(this_object())->add_exp((amount * gain / 100) * -1); 
  }
  old_exp = USER->query_exp();   
  
} 