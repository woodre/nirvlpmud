 cove(int lvl,int pi) {
  object acer, targ;
   if(tp->query_invis()) { write("You are invis!\n"); return 1; }
   if(tp->query_attack()) { write("You are in combat!\n"); return 1; }
     if(cove_var[1] > tsp) { write("You are low on energy.\n"); return 1; }
     if(cove_var[2] > thp) { write("You are low on physical energy.\n"); return 1; }
     if(cove_var[3] > tp->query_exp()) { write("You are low on exp.\n"); return 1; }
     if(cove_var[4] > tp->query_money()) { write("You are low on money.\n"); return 1; }
     tp->add_spell_point(-cove_var[1]);
     tp->add_hit_point(-cove_var[2]);
     if(hob) tp->add_xp(-cove_var[3]); else tp->add_exp(-cove_var[3]);
     tp->add_money(-cove_var[4]); 
     if(!check(lvl,pi,cove_var[6],cove_var[7],cove_var[8])) { 
     write("Your cove fails!\n");
   return 1; }
     if(targ=present("cove_reg",etp)) {} 
     else targ = clone_object(root+"obj/cove.c");
     targ->set_base(lvl+pi);
     move_object(targ,etp);
     
     write("You raise your staff and you intone:\n\n");
     say(tp->query_name()+" raises "+tp->query_possessive()+" Staff and intone:\n\n");
     tell_room(etp,"   In the name of our Founder, Rose Vyr, let the Healing begin!\n");
 return 1; }
