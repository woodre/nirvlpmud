int LVV;
string LVO;
potion(int lvl,int pi) {
     if(potion_var[1] > tsp) { write("You are low on energy.\n"); return 1; }
     if(potion_var[2] > thp) { write("You are low on physical energy.\n"); return 1; }
     if(potion_var[3] > tp->query_exp()) { write("You are low on exp.\n"); return 1; }
     if(potion_var[4] > tp->query_money()) { write("You are low on money.\n"); return 1; }
     tp->add_spell_point(-potion_var[1]);
     tp->add_hit_point(-potion_var[2]);
     if(hob) tp->add_xp(-potion_var[3]); else tp->add_exp(-potion_var[3]);
     tp->add_money(-potion_var[4]); 
     if(!check(lvl,pi,potion_var[6],potion_var[7],potion_var[8])) { 
     write("Your Potion Creation fails!\n");
   return 1; } 
     write("You pull out a vial, some herbs, and a piece of Jade.\n"+
           "You proceed to make a potion of healing.\n");
     say(tp->query_name()+" pulls out a vial, some herbs, and a piece of Jade.\n"+
         tp->query_name()+" intones quietly as a potion is being made.\n");
     if(!LVV) { LVV = ({lvl}); LVO = ({tpn}); }
     else { LVV += ({lvl}); LVO += ({tpn}); }
     call_out("creating_potion",60 - (lvl+pi),tp);
 return 1; }
 
 creating_potion(object targ) {
 object pot;
 int mm;
     mm = member_array(targ->query_real_name(),LVO);
     pot = clone_object(root+"obj/potion.c");
     pot->set_heal(LVV[mm]);
     move_object(pot,targ);
     LVV -= ({LVV[mm]}); LVO -= ({LVO[mm]});
     tell_room(environment(targ),targ->query_name()+" has created a potion of healing.\n");
 return 1; }
     
     
     
     
