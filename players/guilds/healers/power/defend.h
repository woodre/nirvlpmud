 defend(int lvl,int pi,string who) {
  object targ, acer;
   if(!who) { write("Who do you wish to defend?\n"); return 1; }
   if(!(targ=present(who,etp))) {
     write("That person is not here!\n");
   return 1; }
   if(!living(targ)) { write("You may only cast upon something living.\n"); return 1; }
   if(targ->query_invis() > tl) { write("That person is not here!\n"); return 1; }
   if(targ->query_ghost()) { write("You can not cast upon a ghost!\n"); return 1; }
   if(targ->query_level() > 19)  { write("You can not cast upon a wiz!\n"); return 1; }
   if(targ->query_real_name() == "guest") { write("Guest may not be healed.\n"); return 1; }
     if(defend_var[1] > tsp) { write("You are low on energy.\n"); return 1; }
     if(defend_var[2] > thp) { write("You are low on physical energy.\n"); return 1; }
     if(defend_var[3] > tp->query_exp()) { write("You are low on exp.\n"); return 1; }
     if(defend_var[4] > tp->query_money()) { write("You are low on money.\n"); return 1; }
    if(present("defend_spell", targ)) {
      write("That person already has a defend spell!\n");
      return 1;
    }
     tp->add_spell_point(-defend_var[1]);
     tp->add_hit_point(-defend_var[2]);
     if(hob) tp->add_xp(-defend_var[3]); else tp->add_exp(-defend_var[3]);
     tp->add_money(-defend_var[4]);  
     if(!check(lvl,pi,defend_var[6],defend_var[7],defend_var[8])) { 
     write("Your defend fails!\n");
   return 1; }
/* Changed this so it works with the new armor system. -Feldegast 1-1-00
     acer = clone_object(root+"obj/ac.c");
     acer->class(lvl/10);
     move_object(acer,targ);
*/
    acer = clone_object(root+"obj/defend_spell.c");
    acer->start(targ,lvl/10);
     write("You touch "+capitalize(targ->query_real_name())+" and intone.\n"+
           capitalize(targ->query_real_name())+"'s armor class increases!\n");
     say(tp->query_name()+" reaches out and touches "+targ->query_name()+".\nLight streams outward from "+
         tp->query_name()+"'s hand.\n"); 
 return 1; }
