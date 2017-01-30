grant(int lvl,int pi,string who,string what) {
  object targ, tbo;
  object trans;
   if(!who) { write("Who do you wish to grant power to?\n"); return 1; }
   if(!what) { write("What spell do you wish to grant?\n"); return 1; }
   if(what == "grant" || what == "mystic_transfer" || what == "robe_of_healing" || what == "holy_blessing" ||
      what == "mass_heal" || what == "mass_full_heal") { 
        write("You may not grant that power.\n"); return 1; }
   if(!(targ=present(who,etp))) {
     write("That person is not in game!\n");
   return 1; }
   if(targ == tp) { write("You may not cast this on yourself!\n"); return 1; }
   if(!living(targ)) { write("You may garnt power to living beings only.\n"); return 1; }
   if(targ->query_invis() > tl) { write("That person is not here!\n"); return 1; }
   if(targ->query_ghost()) { write("You can not grant powers to a ghost!\n"); return 1; }
   if(targ->query_level() > 19)  { write("You can not grant power to a wiz!\n"); return 1; }
   if(targ->query_real_name() == "guest") { write("Guest may not be healed.\n"); return 1; }
     if(grant_var[1] > tsp) { write("You are low on energy.\n"); return 1; }
     if(grant_var[2] > thp) { write("You are low on physical energy.\n"); return 1; }
     if(grant_var[3] > tp->query_exp()) { write("You are low on exp.\n"); return 1; }
     if(grant_var[4] > tp->query_money()) { write("You are low on money.\n"); return 1; }
     tp->add_spell_point(-grant_var[1]);
     tp->add_hit_point(-grant_var[2]);
     if(hob) tp->add_xp(-grant_var[3]); else tp->add_exp(-grant_var[3]);
     tp->add_money(-grant_var[4]);  
     if(!check(lvl,pi,grant_var[6],grant_var[7],grant_var[8])) { 
     write("Your Granting of a Power fails!\n");
   return 1; }
     trans = clone_object(root+"obj/grant.c");
     trans->set_spell(what);
     trans->set_level(lvl/2);
     trans->set_piety(pi/2);
     move_object(trans,targ);
   write("You close your eyes and pray for moment.\nYou have granted "+what+" to "+capitalize(targ->query_real_name())+"\n");
   say(tp->query_name()+" closes "+tp->query_possessive()+" eyes and intones for a moment.\n");
   tell_room(environment(targ),"A staff of light appears in "+targ->query_name()+"'s hand.\n");
   tell_object(targ,tp->query_name()+" has granted the power of "+what+" to you!\n");
 return 1; }
