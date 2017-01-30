peace(int lvl,int pi,string who) {
  object targ;
  int z;
   if(who) {
     if(!(targ=present(who,etp))) {
       write("That person is not here!\n");
     return 1; } 
   if(!living(targ)) { write("You may only cast upon something living.\n"); return 1; }
     if(targ->query_invis() > tl) { write("That person is not here!\n"); return 1; }
     if(targ->query_level() > 19)  { write("You can not cast upon a wiz!\n"); return 1; }
     if(targ->query_attack()) { write(capitalize(who)+" is not in combat.\n"); return 1;}
     if(targ->is_player() && (targ->query_level() + targ->query_extra_level()) > lvl && targ != tp) {
       write("You can not target peace on a player equal \n"+
              "to or higher than your level!\n");
       return 1;}
   } 
   if(peace_var[1] > tsp) { write("You are low on energy.\n"); return 1; }
   if(peace_var[2] > thp) { write("You are low on physical energy.\n"); return 1; }
   if(peace_var[3] > tp->query_exp()) { write("You are low on exp.\n"); return 1; }
   if(peace_var[4] > tp->query_money()) { write("You are low on money.\n"); return 1; }
   tp->add_spell_point(-peace_var[1]);
   tp->add_hit_point(-peace_var[2]);
   if(hob) tp->add_xp(-peace_var[3]); else tp->add_exp(-peace_var[3]);
   tp->add_money(-peace_var[4]);
   if(!check(lvl,pi,peace_var[6],peace_var[7],peace_var[8])) { 
     write("Your peace spell fails!\n");
   return 1; } 
   if(who) {
     
      (targ->query_attack())->stop_fight(); targ->stop_fight(); 
      (targ->query_attack())->stop_fight(); targ->stop_fight();
      write("You calm "+targ->query_name()+" down.\n");
      say(targ->query_name()+" is calmed by "+capitalize(tpn)+".\n");
    return 1; } 
      targ=all_inventory(environment(tp));
      for(z=0;z<sizeof(targ);z++) {
        if(living(targ[z])) {
         if(targ[z]->query_attack()) { (targ[z]->query_attack())->stop_fight();
          targ[z]->stop_fight(); } }
      }
      for(z=0;z<sizeof(targ);z++) {
        if(living(targ[z])) {
          if(targ[z]->query_attack()) { targ[z]->stop_fight(); } }
      }
   write("You bring peace to all!\n");
   say(capitalize(tpn)+" calls PEACE upon all!\n");
 return 1; }
