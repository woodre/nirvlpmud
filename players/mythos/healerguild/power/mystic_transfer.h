mystic_transfer(int lvl,int pi,string who,string what) {
  object targ, tbo;
  object trans;
   if(!who) { write("Who do you wish to transfer to?\n"); return 1; }
   if(!what) { write("What spell do you wish to transfer?\n"); return 1; }
   if(what == "mystic_transfer" || what == "grant" || what == "holy_blessing" ||
      what == "robe_of_healing"  || what == "mass_heal" || what == "mass_full_heal" ){ 
      write("You may not transfer that spell.\n"); return 1; }
   if(!(targ=find_player(who))) {
     write("That person is not in game!\n");
   return 1; }
   if(targ == tp) { write("You may not cast this on yourself!\n"); return 1; }
   if(targ->query_invis() > tl) { write("That person is not here!\n"); return 1; }
   if(targ->query_ghost()) { write("You can not transfer to a ghost!\n"); return 1; }
   if(targ->query_level() > 19)  { write("You can not transfer to a wiz!\n"); return 1; }
   if(!(tbo=present("mythos_healer",targ))) { write("That person is not a healer.\n"); return 1; }
     if(mystic_transfer_var[1] > tsp) { write("You are low on energy.\n"); return 1; }
     if(mystic_transfer_var[2] > thp) { write("You are low on physical energy.\n"); return 1; }
     if(mystic_transfer_var[3] > tp->query_exp()) { write("You are low on exp.\n"); return 1; }
     if(mystic_transfer_var[4] > tp->query_money()) { write("You are low on money.\n"); return 1; }
     tp->add_spell_point(-mystic_transfer_var[1]);
     tp->add_hit_point(-mystic_transfer_var[2]);
     if(hob) tp->add_xp(-mystic_transfer_var[3]); else tp->add_exp(-mystic_transfer_var[3]);
     tp->add_money(-mystic_transfer_var[4]); 
     if(!check(lvl,pi,mystic_transfer_var[6],mystic_transfer_var[7],mystic_transfer_var[8])) { 
     write("Your Mystic Transfer fails!\n");
   return 1; } 
     trans = clone_object(root+"obj/mystic.c");
     trans->set_spell(what);
     trans->set_level(lvl);
     trans->set_piety(pi);
     move_object(trans,targ);
   write("You close your eyes and pray for moment.\nYou have transferred "+what+ " to "+capitalize(targ->query_real_name())+"\n");
   say(tp->query_name()+" closes "+tp->query_possessive()+" eyes and intones for a moment.\n"+
       "A globe of light appears above and then vanishes.\n");
   tell_room(environment(targ),"A globe of light appears and surrounds "+targ->query_name()+".\n");
   tell_object(targ,tp->query_name()+" has transferred "+what+" to you!\n");
 return 1; }
