 haven(int lvl,int pi) {
  object acer, targ;
   if(etp->realm()) { write("Something prevents you from making this place a Haven.\n"); return 1; }
   if(tp->query_invis()) { write("You are invis!\n"); return 1; }
     if(haven_var[1] > tsp) { write("You are low on energy.\n"); return 1; }
     if(haven_var[2] > thp) { write("You are low on physical energy.\n"); return 1; }
     if(haven_var[3] > tp->query_exp()) { write("You are low on exp.\n"); return 1; }
     if(haven_var[4] > tp->query_money()) { write("You are low on money.\n"); return 1; }
     tp->add_spell_point(-haven_var[1]);
     tp->add_hit_point(-haven_var[2]);
     if(hob) tp->add_xp(-haven_var[3]); else tp->add_exp(-haven_var[3]);
     tp->add_money(-haven_var[4]); 
     if(!check(lvl,pi,haven_var[6],haven_var[7],haven_var[8])) { 
       write("Your haven fails!\n");
     return 1; }
     acer = clone_object(root+"obj/haven_shade.c");
     acer->old_short(etp->short());
     acer->start_shadow_haven(etp);
     targ = clone_object(root+"obj/haven.c");
     targ->set_shade_ob(acer);
     targ->set_base(lvl+pi);
     move_object(targ,etp);
     
     write("You raise your staff and you intone:\n\n");
     say(tp->query_name()+" raises "+tp->query_possessive()+" Staff and intone:\n\n");
     tell_room(etp,"   In Servitude to the Oath and in the name of our Founder,\n"+
                   "    Rose Vyr, I claim this place a Haven of Peace!\n\n");
 return 1; }
