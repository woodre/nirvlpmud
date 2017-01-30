int LLL;
string LLLN;
healing_spring(int lvl,int pi) {
     if(healing_spring_var[1] > tsp) { write("You are low on energy.\n"); return 1; }
     if(healing_spring_var[2] > thp) { write("You are low on physical energy.\n"); return 1; }
     if(healing_spring_var[3] > tp->query_exp()) { write("You are low on exp.\n"); return 1; }
     if(healing_spring_var[4] > tp->query_money()) { write("You are low on money.\n"); return 1; }
     tp->add_spell_point(-healing_spring_var[1]);
     tp->add_hit_point(-healing_spring_var[2]);
     if(hob) tp->add_xp(-healing_spring_var[3]); else tp->add_exp(-healing_spring_var[3]);
     tp->add_money(-healing_spring_var[4]);  
      if(!check(lvl,pi,healing_spring_var[6],healing_spring_var[7],healing_spring_var[8])) { 
     write("Your healing Spring Creation fails!\n");
   return 1; }
     write("You bow your head and begin to pray.\n");
     say(tp->query_name()+" bows "+tp->query_possessive()+" head and begins to pray.\n");
     if(!LLL) { LLL = ({lvl}); LLLN = ({tpn}); }
     else { LLL += ({lvl}); LLLN += ({tpn}); }
     call_out("creating_healing_spring",200 - (lvl+pi),tp);
 return 1; }
 
 creating_healing_spring(object targ) {
 object pot;
 int mm;
     mm = member_array(targ->query_real_name(),LLLN);
     pot = clone_object(root+"obj/healing_spring.c");
     pot->set_heal(LLL[mm]);
     pot->set_uses(LLL[mm]);
     move_object(pot,environment(targ));
     LLL -= ({LLL[mm]}); LLLN -= ({LLLN[mm]});
     tell_room(environment(targ),targ->query_name()+" stops praying and with a loud yell, \n"+
               "strikes the ground with the butt of "+targ->query_possessive()+" staff.\n\n"+
               "Water gushes forth - a healing spring.\n");
 return 1; }
     
     
     
     
