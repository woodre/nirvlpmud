robe_of_healing(int lvl,int pi,string who,string what) {
  object targ;
  object trans;
   if(!who) { write("Who do you wish to grant the robe to?\n"); return 1; }
   if(!(targ=present(who,etp))) {
     write("That person is not in game!\n");
   return 1; }
   if(targ == tp) { write("You may not cast this on yourself!\n"); return 1; }
   if(!living(targ)) { write("You may give the robe to living beings only.\n"); return 1; }
   if(targ->query_invis() > tl) { write("That person is not here!\n"); return 1; }
   if(targ->query_ghost()) { write("You can not give the robes to a ghost!\n"); return 1; }
   if(targ->query_level() > 19)  { write("You can not give the robes to a wiz!\n"); return 1; }
   if(targ->query_level() < 5) { write("You can not give the robes to someone below level 5.\n"); return 1;}
   if(targ->query_real_name() == "guest") { write("Guest may not be healed.\n"); return 1; }
   if(present("robe_of_healing",targ)) { write("That person already has a robe!\n"); return 1; }
     if(robe_of_healing_var[1] > tsp) { write("You are low on energy.\n"); return 1; }
     if(robe_of_healing_var[2] > thp) { write("You are low on physical energy.\n"); return 1; }
     if(robe_of_healing_var[3] > tp->query_exp()) { write("You are low on exp.\n"); return 1; }
     if(robe_of_healing_var[4] > tp->query_money()) { write("You are low on money.\n"); return 1; }
     tp->add_spell_point(-robe_of_healing_var[1]);
     tp->add_hit_point(-robe_of_healing_var[2]);
     if(hob) tp->add_xp(-robe_of_healing_var[3]); else tp->add_exp(-robe_of_healing_var[3]);
     tp->add_money(-robe_of_healing_var[4]);  
     if(!check(lvl,pi,robe_of_healing_var[6],robe_of_healing_var[7],robe_of_healing_var[8])) { 
     write("Your creation of a Robe of Healing fails!\n");
   return 1; }
     trans = clone_object(root+"obj/robe_of_healing.c");
     if(targ->query_level() < 17) trans->set_level(targ->query_level()); else trans->set_level(17);
     trans->set_piety(targ->query_attrib("piety"));
     move_object(trans,targ);
   write("You close your eyes and pray for moment.\n");
   say(tp->query_name()+" closes "+tp->query_possessive()+" eyes and intones for a moment.\n");
   tell_room(environment(targ),"A robe of light appears around "+targ->query_name()+".\n");
   tell_object(targ,tp->query_name()+" has bestowed you a Robe of Healing!\n");
 return 1; }
