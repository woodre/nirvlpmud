 cure(int lvl,int pi,string who) {
  object targ, ail;
  int h;
   if(!who) { write("Who do you wish to cure?\n"); return 1; }
   if(!(targ=present(who,etp))) {
     write("That person is not here!\n");
   return 1; }
   if(!living(targ)) { write("You may only cast upon something living.\n"); return 1; }
   if(targ->query_invis() > tl) { write("That person is not here!\n"); return 1; }
   if(targ->query_ghost()) { write("You can not cast upon a ghost!\n"); return 1; }
   if(targ->query_level() > 19)  { write("You can not cast upon a wiz!\n"); return 1; }
     if(cure_var[1] > tsp) { write("You are low on energy.\n"); return 1; }
     if(cure_var[2] > thp) { write("You are low on physical energy.\n"); return 1; }
     if(cure_var[3] > tp->query_exp()) { write("You are low on exp.\n"); return 1; }
     if(cure_var[4] > tp->query_money()) { write("You are low on money.\n"); return 1; }
     tp->add_spell_point(-cure_var[1]);
     tp->add_hit_point(-cure_var[2]);
     if(hob) tp->add_xp(-cure_var[3]); else tp->add_exp(-cure_var[3]);
     tp->add_money(-cure_var[4]); 
     if(!check(lvl,pi,cure_var[6],cure_var[7],cure_var[8])) { 
     write("Your cure fails!\n");
   return 1; }
     ail = all_inventory(targ);
     for (h=0;h<sizeof(ail);h++) {
      if(ail[h]->id("poison")) destruct(ail[h]);
      else if(ail[h]->id("toxin")) destruct(ail[h]);
      else if(ail[h]->id("toxin2")) destruct(ail[h]);
      else if(ail[h]->id("toxin3")) destruct(ail[h]);
      else if(ail[h]->id("crotchrot")) destruct(ail[h]);
      else if(ail[h]->id("disease")) destruct(ail[h]);
      else if(ail[h]->id("virus")) destruct(ail[h]);
      else if(ail[h]->id("worm")) destruct(ail[h]);
      else if(ail[h]->id("illness")) destruct(ail[h]);
      else if(ail[h]->id("sickness")) destruct(ail[h]);
      else if(ail[h]->id("darkness")) destruct(ail[h]);
      else if(ail[h]->id("ill")) destruct(ail[h]);
      else if(ail[h]->id("sick")) destruct(ail[h]);
      else if(ail[h]->id("curse")) destruct(ail[h]);
      else if(ail[h]->id("rot")) destruct(ail[h]);
    } 
   write("You lay your hands on "+who+" and cure "+targ->query_objective()+"\n");
   write("If the person still has the ailment, contact a guild wiz about it.\n");
   say(tp->query_name()+" lays "+tp->query_possessive()+" hands on "+who+".\n");
   tell_object(targ,"You feel better.\nYou have been cured of all ailments.\n");
 return 1; }
