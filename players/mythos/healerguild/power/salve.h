int time;
int LVL;
string LVN;
salve(int lvl,int pi) {
     if(salve_var[1] > tsp) { write("You are low on energy.\n"); return 1; }
     if(salve_var[2] > thp) { write("You are low on physical energy.\n"); return 1; }
     if(salve_var[3] > tp->query_exp()) { write("You are low on exp.\n"); return 1; }
     if(salve_var[4] > tp->query_money()) { write("You are low on money.\n"); return 1; }
     tp->add_spell_point(-salve_var[1]);
     tp->add_hit_point(-salve_var[2]);
     if(hob) tp->add_xp(-salve_var[3]); else tp->add_exp(-salve_var[3]);
     tp->add_money(-salve_var[4]);  
     if(!check(lvl,pi,salve_var[6],salve_var[7],salve_var[8])) { 
     write("Your Salve Creation fails!\n");
   return 1; }
     write("You pull out a tin, some herbs, and a piece of Jade.\n"+
           "You proceed to make a salve of healing.\n");
     say(tp->query_name()+" pulls out a tin, some herbs, and a piece of Jade.\n"+
         tp->query_name()+" intones quietly as a salve is being made.\n");
     if(!LVL) { LVL = ({lvl}); LVN = ({tpn}); }
     else { LVL += ({lvl}); LVN += ({tpn}); }
      time = 60 - (lvl+pi);
      call_out("creating_salve",time,tp);
 return 1; }
 
 creating_salve(object targ) {
 object pot;
 int mm;
     mm = member_array(targ->query_real_name(),LVN);
     pot = clone_object(root+"obj/salve.c");
      pot->set_heal(LVL[mm]);
      pot->set_uses( (LVL[mm]/10) );
      move_object(pot,targ);
     LVL -= ({LVL[mm]}); LVN -= ({LVN[mm]});
     tell_room(environment(targ),targ->query_name()+" has created a salve of healing.\n");
 return 1; }
     
     
     
     
