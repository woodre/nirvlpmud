
 holy_blessing(int lvl,int pi, string who) {
  object acer, targ;
  write("Temporarily disabled.  Sorry Angelique.  We'll get you something soon.\n");
  return 1;
  if(member_array(tpn,cast_bless) != -1) { write("You have already cast a Holy Blessing today.\n"); return 1; } 
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
   if(targ->query_real_name() == "guest") { write("Guest may not be healed.\n"); return 1; } 
     if(holy_blessing_var[1] > tsp) { write("You are low on energy.\n"); return 1; }
     if(holy_blessing_var[2] > thp) { write("You are low on physical energy.\n"); return 1; }
     if(holy_blessing_var[3] > tp->query_exp()) { write("You are low on exp.\n"); return 1; }
     if(holy_blessing_var[4] > tp->query_money()) { write("You are low on money.\n"); return 1; }
     tp->add_spell_point(-holy_blessing_var[1]);
     tp->add_hit_point(-holy_blessing_var[2]);
     if(hob) tp->add_xp(-holy_blessing_var[3]); else tp->add_exp(-holy_blessing_var[3]);
     tp->add_money(-holy_blessing_var[4]);  
     if(!check(lvl,pi,holy_blessing_var[6],holy_blessing_var[7],holy_blessing_var[8])) { 
       write("Your Holy Blessing fails!\n");
     return 1; }
     cast_bless += ({tpn});
     acer = clone_object(root+"obj/blessing.c");
     acer->set_threshold(7);
     acer->shadow_blessing_on(targ);
     write("\nYou raise your staff and in a great voice you shout:\n");
     say(tp->query_name()+" raises the "+tp->query_possessive()+" Staff and shouts:\n");
     tell_room(etp,"   In Servitude to the Oath and in the name of our Founder,\n"+
                   "    Rose Vyr, let all KNOW that "+targ->query_name()+" is\n"+
                   "    BLESSED.  Let no harm befall "+targ->query_objective()+"!\n\n");
 return 1; }
