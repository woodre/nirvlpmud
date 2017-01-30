heart_beat() 
{
  if(!environment()) return;
  if(!environment(this_object())->is_player()) return;
  if(!environment(this_object())->query_interactive()) return;

  HBeats++;
  
/* experience stuff *******************************************************/ 
  if(OldXP < 1) OldXP = environment(this_object())->query_exp();     /* Deal with exp gain */
  
  if((OldXP + 8) < environment(this_object())->query_exp()) {        /* +8 for small adds */
    int gain, amount;
    gain = environment(this_object())->query_exp() - OldXP;
    amount = 0;
    if(GuildXP < 4882813) {                                          /* 15-30% guild leveling */
      GuildXP += ((GXPGain * gain) / 100);
      amount += GXPGain;
      check_glevel();
    }    
    environment(this_object())->add_exp((amount * gain / 100) * -1); 
  }
  OldXP = environment(this_object())->query_exp();   
  
/* spell stuff ************************************************************/
  if(SymbolPain)
    SymbolPain = 0;  
  
} 