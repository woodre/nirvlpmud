 mass_heal(int lvl,int pi,string *mass_p,string typ,int healamount) {
  object targ;
  int lvv, XX, ok;
  int i, spm, hpm, HV;
  ok = spm = hpm = 0;
  XX = 2 + random(2);
   if(pi > 200) { lvv = tl + tx; HV = lvl * mass_heal_var[5]; } 
   else { lvv = lvl*(1+random(3)); HV = lvl * mass_heal_var[5]/2 + random(lvl * mass_heal_var[5]/2); }
     if(lvv * mass_heal_var[1] > tsp) { write("You are low on energy.\n"); return 1; }
     if(mass_heal_var[2] > thp) { write("You are low on physical energy.\n"); return 1; }
     if(mass_heal_var[3] > tp->query_exp()) { write("You are low on exp.\n"); return 1; }
     if(mass_heal_var[4] > tp->query_money()) { write("You are low on money.\n"); return 1; }
     tp->add_spell_point(-lvv * mass_heal_var[1]);
     tp->add_hit_point(-mass_heal_var[2]);
     if(hob) tp->add_xp(-mass_heal_var[3]); else tp->add_exp(-mass_heal_var[3]);
     tp->add_money(-mass_heal_var[4]);  
     if(!check(lvl,pi,mass_heal_var[6],mass_heal_var[7],mass_heal_var[8])) { 
       write("Your mass healing fails!\n");
     return 1; }
     write("You raise a hand and chant.\n");
     say(tp->query_name()+" raises a hand and chants.\n");
     tell_room(etp,"There is a burst of LIGHT.\n");
    for(i=0;i<sizeof(mass_p);i++) {
      if(mass_p[i]) {
      targ=present(mass_p[i],etp);
      if(targ) {
      if(living(targ) && !(targ->query_invis() >  tl) && !targ->query_ghost() && !(targ->query_level() > 19))  { 
          XX = XX + lvv/10;
		  hpm = targ->query_mhp() - targ->query_hp();
          spm = targ->query_msp() - targ->query_sp();
		  if(healamount) if(HV > healamount) HV = healamount;
          if(HV < hpm) hpm = HV;
          if(HV < spm) spm = HV;
        if(typ == "hp" || typ == "sp") {
		if(typ == "hp") if(!targ->add_hit_point(HV)) ok = 1;
        if(typ == "sp") if(!targ->add_spell_point(HV)) ok = 1;
        } else 
		if(typ != "hp" && typ != "sp") if(!targ->heal_self(HV)) ok = 1;
		if(ok) {
       if(typ != "hp" && typ != "sp") 
	      write("You healed "+capitalize(targ->query_real_name())+" "+hpm+" hps and "+spm+" sps.\n");
		if(typ == "sp") write("You healed "+capitalize(targ->query_real_name())+" "+spm+" sps.\n"); }
		if(typ == "hp") write("You healed "+capitalize(targ->query_real_name())+" "+hpm+" hps.\n");
        tell_object(targ,tp->query_name()+" has healed you!\n");
         if(hob && targ != tp && !present("mythos_healer",targ) && 
                   targ->query_real_name() != "guest") {
          if(typ != "hp") tp->add_xp(spm * XX);
          if(typ != "sp") tp->add_xp(hpm * XX);
         }
        }
		}
      }
      }
 return 1; }
