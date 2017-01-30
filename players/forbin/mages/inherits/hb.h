heart_beat() 
{
  if(!environment()) return;
  if(!environment(this_object())->is_player()) return;
  if(!environment(this_object())->query_interactive()) return;

  HBeats++;
  
  if(OldXP < 1) OldXP = environment(this_object())->query_exp();     /* Deal with exp gain */
  
  if((OldXP + 8) < environment(this_object())->query_exp()) {        /* +8 for small adds */
    int gain, amount;
    gain = environment(this_object())->query_exp() - OldXP;
    amount = 0;
    if(SchoolsXP < 4500000) {                                        /* 15% to magic schools */
      SchoolsXP += ((15 * gain) / 100);
      amount += 15;
      check_schools();
      advance_checks();
    }    
    if(AttribsXP < 2000000) {                                        /* 10% to guild attributes */
      AttribsXP += ((10 * gain) / 100);
      amount += 10;
      check_attributes();
      advance_checks();
    }
    environment(this_object())->add_exp((amount * gain / 100) * -1); 
  }
  OldXP = environment(this_object())->query_exp();   
  
} 