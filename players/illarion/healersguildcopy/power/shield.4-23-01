shield(int lvl,int pi,string who) {
  object targ, acer;
   if(!who) { write("Who do you wish to shield?\n"); return 1; }
   if(!(targ=present(who,etp))) {
     write("That person is not here!\n");
   return 1; }
   if(!living(targ)) { write("You may only cast upon something living.\n"); return 1; }
   if(targ->query_invis() > tl) { write("That person is not here!\n"); return 1; }
   if(targ->query_ghost()) { write("You can not cast upon a ghost!\n"); return 1; }
   if(targ->query_level() > 19) { write("You can not cast upon a wiz!\n"); return 1; }
   if(targ->query_real_name() == "guest") { write("Guest may not be healed.\n"); return 1; }
     if(shield_var[1] > tsp) { write("You are low on energy.\n"); return 1; }
     if(shield_var[2] > thp) { write("You are low on physical energy.\n"); return 1; }
     if(shield_var[3] > tp->query_exp()) { write("You are low on exp.\n"); return 1; }
     if(shield_var[4] > tp->query_money()) { write("You are low on money.\n"); return 1; }
     tp->add_spell_point(-shield_var[1]);
     tp->add_hit_point(-shield_var[2]);
     if(hob) tp->add_xp(-shield_var[3]); else tp->add_exp(-shield_var[3]);
     tp->add_money(-shield_var[4]);  
      if(!check(lvl,pi,shield_var[6],shield_var[7],shield_var[8])) { 
     write("Your shield fails!\n");
   return 1; }
/*
     if(acer = present("shielding",targ)) {}
     else acer = clone_object(root+"obj/shield.c");
     acer->set_base(lvl);
     move_object(acer,targ);
*/
    if(acer = present("shield_spell",targ)) {
       write("You touch "+capitalize(targ->query_real_name())+" and intone.\n"+
             "The shield of Light surrounding "+capitalize(targ->query_real_name())+" is strengthened!\n");
       say(tp->query_name()+" reaches out and touches "+targ->query_name()+".\n"+
           "The Shield of Light surrounding "+targ->query_name()+" is strenghthened!\n"); 

       acer->charge(lvl*4); /* Increases duration */
     }
     else {
       acer = clone_object(root+"obj/shield_spell.c");
      acer->start(targ, 10+(lvl*2), lvl*10); /* target, resistance, duration */
       write("You touch "+capitalize(targ->query_real_name())+" and intone.\n"+
             "A shield of Light surrounds "+capitalize(targ->query_real_name())+"!\n");
       say(tp->query_name()+" reaches out and touches "+targ->query_name()+".\n"+
           "A Shield of Light surrounds "+targ->query_name()+"\n"); 
     }
     
     return 1; 
}
