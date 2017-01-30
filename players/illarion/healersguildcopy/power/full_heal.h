 full_heal(int lvl,int pi,string who) {
  object targ;
  int spm, hpm, HV;
  spm = hpm = 0;
   if(!who) { write("Who do you wish to full heal?\n"); return 1; }
   if(!(targ=present(who,etp))) {
     write("That person is not here!\n");
   return 1; }
   if(!living(targ)) { write("You may only cast upon something living.\n"); return 1; }
   if(targ->query_invis() > tl) { write("That person is not here!\n"); return 1; }
   if(targ->query_ghost()) { write("You can not cast upon a ghost!\n"); return 1; }
   if(targ->query_level() > 19)  { write("You can not cast upon a wiz!\n"); return 1; }
   if(targ->query_real_name() == "guest") { write("Guest may not be healed.\n"); return 1; }
     if(full_heal_var[1] > tsp) { write("You are low on energy.\n"); return 1; }
     if(full_heal_var[2] > thp) { write("You are low on physical energy.\n"); return 1; }
     if(full_heal_var[3] > tp->query_exp()) { write("You are low on exp.\n"); return 1; }
     if(full_heal_var[4] > tp->query_money()) { write("You are low on money.\n"); return 1; }
     tp->add_spell_point(-full_heal_var[1]);
     tp->add_hit_point(-full_heal_var[2]);
     if(hob) tp->add_xp(-full_heal_var[3]); else tp->add_exp(-full_heal_var[3]);
     tp->add_money(-full_heal_var[4]);  
     if(!check(lvl,pi,full_heal_var[6],full_heal_var[7],full_heal_var[8])) { 
     write("Your full heal fails!\n");
   return 1; }
     hpm = targ->query_mhp() - targ->query_hp();
     spm = targ->query_msp() - targ->query_sp();
     if(!query_ip_name(targ)) { hpm /= 4; spm = 0; }
    targ->heal_self(full_heal_var[5]);
   if(hob && targ != tp) {
     tp->add_xp(spm);
     tp->add_xp(hpm);
   }
   write("As you quietly chant, you touch the top of your staff to "+capitalize(targ->query_real_name())+"'s head.\n");
   say(tp->query_name()+" quietly chants and touches the top of "+tp->query_possessive()+" staff to "+targ->query_name()+"'s head.\n"); 
   tell_room(etp,"A bright light blazes out from the point of contact!\n");
   tell_object(targ,"You feel good.\n");
 return 1; }
