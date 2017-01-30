simulcrum(int lvl,int pi,string who) {
  object targ;
  object sim;
object WHO;
   if(!who) who = tpn;
   if(!(targ=present(who,etp))) {
       write("That person is not here!\n");
     return 1; }
   if(!living(targ)) { write("You may only cast upon something living.\n"); return 1; }
     if(targ->query_invis() > tl) { write("That person is not here!\n"); return 1; }
     if(targ->query_ghost()) { write("That person is a ghost.\n"); return 1; }
   if(targ->query_level() > 19)  { write("You can not cast upon a wiz!\n"); return 1; }
     if(targ->query_real_name() == "guest") { write("Guest may not be healed.\n"); return 1; }
     if(!targ->query_attack()) { write(capitalize(who)+" is not in combat.\n"); return 1;} 
   if(simulcrum_var[1] > tsp) { write("You are low on energy.\n"); return 1; }
   if(simulcrum_var[2] > thp) { write("You are low on physical energy.\n"); return 1; }
   if(simulcrum_var[3] > tp->query_exp()) { write("You are low on exp.\n"); return 1; }
   if(simulcrum_var[4] > tp->query_money()) { write("You are low on money.\n"); return 1; }
   tp->add_spell_point(-simulcrum_var[1]);
   tp->add_hit_point(-simulcrum_var[2]);
   if(hob) tp->add_xp(-simulcrum_var[3]); else tp->add_exp(-simulcrum_var[3]);
   tp->add_money(-simulcrum_var[4]);  
   if(!check(lvl,pi,simulcrum_var[6],simulcrum_var[7],simulcrum_var[8])) { 
     write("Your simulcrum spell fails!\n");
   return 1; }
   write("You raise your staff high in the air and bring forth a illusion of "+capitalize(targ->query_real_name())+"\n");
   say(tp->query_name()+" raises the Staff of Healing and brings forth a illusion of "+targ->query_name()+".\n");
    WHO = targ->query_attack();
   sim = clone_object("/players/mythos/healerguild/mon/ill.c"); 
   sim->set_name(targ->query_real_name());
   sim->set_short(targ->short());
   sim->set_level(1);
   sim->set_hp(100);
   sim->set_ac(0);
   sim->set_wc(0);
   sim->set_no_exp_value();
   move_object(sim,environment(targ->query_attack()));
    WHO->attack_object(sim); targ->stop_fight();
    WHO->attack_object(sim); targ->stop_fight();
   if(sim) { WHO->attack_object(sim); targ->stop_fight(); }
return 1; }
