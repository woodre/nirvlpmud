
 absorption(int lvl,int pi, string who) {
  object acer, targ; 
   if(member_array(tpn,min_bless) != -1) { 
     write("You have already given a Minor Blessing.\nPlease wait till next reset.\n"); return 1; }
   if(!who) { write("Who do you wish to Bless?\n"); return 1; }
   if(!(targ=present(who,etp))) { write("That person is not here.\n"); return 1; }
   if(tp->query_invis()) { write("You are invis!\n"); return 1; }
   if(!living(targ)) { write("Only upon the living can you Bless.\n"); return 1; }
   if(targ->query_invis() > tl) { write("That person is not here.\n"); return 1; }
   if(targ->query_level() > 19) { write("You may not bless a wiz.\n"); return 1; }
   if(targ->query_invis()) { write("That person is invis!\n"); return 1; }
   if(targ->query_attack()) { write("That person is in combat!\n"); return 1; }
   if(tp->query_attack()) { write("You are in combat!\n"); return 1; }
   if(targ->query_hunted()) { write("That person is being hunted!\n"); return 1; }
     if(absorption_var[1] > tsp) { write("You are low on energy.\n"); return 1; }
     if(absorption_var[2] > thp) { write("You are low on physical energy.\n"); return 1; }
     if(absorption_var[3] > tp->query_exp()) { write("You are low on exp.\n"); return 1; }
     if(absorption_var[4] > tp->query_money()) { write("You are low on money.\n"); return 1; }
     tp->add_spell_point(-absorption_var[1]);
     tp->add_hit_point(-absorption_var[2]);
     if(hob) tp->add_xp(-absorption_var[3]); else tp->add_exp(-absorption_var[3]);
     tp->add_money(-absorption_var[4]);  
     if(!check(lvl,pi,absorption_var[6],absorption_var[7],absorption_var[8])) { 
       write("Your Minor Blessing fails!\n");
     return 1; }
     min_bless -= ({tpn});
     acer = clone_object(root+"obj/blessing.c");
     acer->set_threshold((lvl+pi)*2);
     acer->shadow_blessing_on(targ);
     write("\nYou raise your staff and in a great voice you intone:\n");
     say(tp->query_name()+" raises the "+tp->query_possessive()+" Staff and intones:\n");
     tell_room(etp,"   In Servitude to the Oath, I - "+tp->query_name()+" - Bless "+targ->query_name()+"!\n\n");
 return 1; }
