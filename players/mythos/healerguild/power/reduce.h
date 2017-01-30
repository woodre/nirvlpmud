 reduce(int lvl,int pi,string who) {
  object targ;
  int som, ixm, stm, HV;
  int RD;
  RD = 5;
  som = ixm = stm = 0;
   if(!who) { write("Who do you wish to reduce soak, intox, and stuff?\n"); return 1; }
   if(!(targ=present(who,etp))) {
     write("That person is not here!\n");
   return 1; }
   if(!living(targ)) { write("You may only cast upon something living.\n"); return 1; }
   if(targ->query_invis() > tl) { write("That person is not here!\n"); return 1; }
   if(targ->query_ghost()) { write("You can not cast upon a ghost!\n"); return 1; }
   if(targ->query_level() > 19)  { write("You can not cast upon a wiz!\n"); return 1; }
   if(targ->query_real_name() == "guest") { write("Guest may not be healed.\n"); return 1; }
     if(1 * reduce_var[1] > tsp) { write("You are low on energy.\n"); return 1; }
     if(reduce_var[2] > thp) { write("You are low on physical energy.\n"); return 1; }
     if(reduce_var[3] > tp->query_exp()) { write("You are low on exp.\n"); return 1; }
     if(reduce_var[4] > tp->query_money()) { write("You are low on money.\n"); return 1; }
     tp->add_spell_point(-1 * reduce_var[1]);
     tp->add_hit_point(-reduce_var[2]);
     if(hob) tp->add_xp(-reduce_var[3]); else tp->add_exp(-reduce_var[3]);
     tp->add_money(-reduce_var[4]);  
     if(!check(lvl,pi,reduce_var[6],reduce_var[7],reduce_var[8])) { 
     write("Your reduce fails!\n");
   return 1; }
     ixm = targ->query_intoxination();
     som = targ->query_soak();
     stm = targ->query_stuffed();
     HV = lvl * 1 * reduce_var[5]/2 + random(lvl * 1 * reduce_var[5]/2);
     if(HV < ixm) ixm = HV/RD; else ixm /= RD;
     if(HV < som) som = HV/RD; else som /= RD;
     if(HV < stm) stm = HV/RD; else stm /= RD;
     if(!query_ip_name(targ)) ixm = som = stm = 0;
     targ->add_intoxination(-HV);                     
     targ->add_stuffed(-HV);
     targ->add_soaked(-HV);
   if(hob) {
     tp->add_xp(som);
     tp->add_xp(ixm);
     tp->add_xp(stm);
   }
   write("You lay your hand on "+capitalize(who)+" and reduce "+targ->query_pronoun()+" soak, intox, and stuff.\n");
   say(tp->query_name()+" lays "+tp->query_possessive()+" hands on "+capitalize(who)+".\n"+
       tp->query_name()+" intones quietly.\n");
   tell_object(targ,"Your intox, stuff, and soak are reduced.\n");
 return 1; }
