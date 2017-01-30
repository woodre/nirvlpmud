 regenerate(int lvl,int pi,string who) {
  object targ, acer;
  int hsp,ssp;
   if(!who) { write("Who do you wish to regenerate?\n"); return 1; }
   if(!(targ=present(who,etp))) {
     write("That person is not here!\n");
   return 1; }
   if(!living(targ)) { write("You may only cast upon something living.\n"); return 1; }
   if(targ->query_invis() > tl) { write("That person is not here!\n"); return 1; }
   if(targ->query_ghost()) { write("You can not cast upon a ghost!\n"); return 1; }
   if(targ->query_level() > 19) { write("You can not cast upon a wiz!\n"); return 1; }
   if(targ->query_attack()) { write("That person is in combat!\n"); return 1; }
   if(targ->query_real_name() == "guest") { write("Guest may not be healed.\n"); return 1; }
     if(regenerate_var[1] > tsp) { write("You are low on energy.\n"); return 1; }
     if(regenerate_var[2] > thp) { write("You are low on physical energy.\n"); return 1; }
     if(regenerate_var[3] > tp->query_exp()) { write("You are low on exp.\n"); return 1; }
     if(regenerate_var[4] > tp->query_money()) { write("You are low on money.\n"); return 1; }
     tp->add_spell_point(-regenerate_var[1]);
     tp->add_hit_point(-regenerate_var[2]);
     if(hob) tp->add_xp(-regenerate_var[3]); else tp->add_exp(-regenerate_var[3]);
     tp->add_money(-regenerate_var[4]);  
      if(!check(lvl,pi,regenerate_var[6],regenerate_var[7],regenerate_var[8])) { 
     write("Your regenerate fails!\n");
   return 1; }
     hsp = targ->query_mhp() - targ->query_hp();
     ssp = targ->query_msp() - targ->query_sp();
     if(acer = present("heal_reg",targ)) {}
     else acer = clone_object(root+"obj/reg.c");
     acer->set_base(lvl);
     move_object(acer,targ);
     write("You press your palm against "+capitalize(targ->query_real_name())+"'s forehead.\n"+
           "You intone quietly.\n");
     say(tp->query_name()+" presses a palm against "+targ->query_name()+"'s forehead and intones.\n");
     tell_room(etp,"\nThere is a FLASH of light!\n\n");
     write("You have cast regenerate on "+capitalize(targ->query_real_name())+".\n");
     tell_object(targ,"You begin to heal at a rapid rate.\n");
     if(targ != tp) { if(hob) tp->add_xp(hsp+ssp); else tp->add_exp(hsp+ssp);  }
 return 1; }
