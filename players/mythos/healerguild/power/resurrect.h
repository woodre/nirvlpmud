resurrect(int lvl,int pi,string who) {
  object targ;
  int xg;
   if(!who) { write("Who do you wish to resurrect?\n"); return 1; }
   if(!(targ=present(who,etp))) {
     write("That person is not here!\n");
   return 1; }
   if(targ == tp) { write("You may not cast this on yourself!\n"); return 1; }
   if(targ->query_invis() > tl) { write("That person is not here!\n"); return 1; }
   if(!targ->query_ghost()) { write("That person is not a ghost!\n"); return 1; }
   if(targ->query_level() > 19)  { write("You can not cast on a wiz!\n"); return 1; }
   if(targ->query_real_name() == "guest") { write("Guest may not be healed.\n"); return 1; }
     if(resurrect_var[1] > tsp) { write("You are low on energy.\n"); return 1; }
     if(resurrect_var[2] > thp) { write("You are low on physical energy.\n"); return 1; }
     if(resurrect_var[3] > tp->query_exp()) { write("You are low on exp.\n"); return 1; }
     if(resurrect_var[4] > tp->query_money()) { write("You are low on money.\n"); return 1; }
     tp->add_spell_point(-resurrect_var[1]);
     tp->add_hit_point(-resurrect_var[2]);
     if(hob) tp->add_xp(-resurrect_var[3]); else tp->add_exp(-resurrect_var[3]);
     tp->add_money(-resurrect_var[4]);  
     if(!check(lvl,pi,resurrect_var[6],resurrect_var[7],resurrect_var[8])) { 
     write("Your Resurrection fails!\n");
   return 1; }
   write("Pointing your staff at "+capitalize(targ->query_real_name())+", you intone the Prayer of Resurrection.\n");
   say(tp->query_name()+" points the Staff of Healing at a ghost and intones.\n");
   tell_room(etp,"A globe of light appears and surrounds "+targ->query_name()+".\n");
   /*
   xg = (targ->query_exp()/24) * lvl/10;
   if(present("mythos_healer",targ)) targ->add_xp(xg); else targ->add_exp(xg);
   */
   targ->heal_self(lvl*2);
   targ->remove_ghost();
   if(hob) tp->add_xp(lvl*4); else tp->add_exp(lvl*4);
 return 1; }
