/*** Changes made on 4.23.01 by Maledicta with
     Boltar's Approval.  Do NOT change this back
     Without Boltar's Okay
 ***/

heal(int lvl,int pi,string who,string typ,int healamount,int multp,object caster) {
  object targ;
  object castee;
  int lvv;
  int ok, XX;
  int spm, hpm, HV;

  ok = spm = hpm = 0;
  XX = 5 + random(3);

  if(caster) { castee = caster; } else {
	  castee = this_player(); }
  if(multp) XX = XX + multp;;
   if(!who) { tell_object(castee,"Who do you wish to heal?\n"); return 1; }
   if(!(targ=present(who,environment(castee)))) {
     tell_object(castee,"That person is not here!\n");
   return 1; }
   if(!living(targ)) { tell_object(castee,"You may only cast upon something living.\n"); return 1; }
   if(targ->query_invis() > tl) { tell_object(castee,"That person is not here!\n"); return 1; }
   if(targ->query_ghost()) { tell_object(castee,"You can not cast upon a ghost!\n"); return 1; }
   if(targ->query_level() > 19 && targ->is_player())  { tell_object(castee,"You can not cast upon a wiz!\n"); return 1; }
   if(targ->query_real_name() == "guest") { tell_object(castee,"Guest may not be healed.\n"); return 1; }
   if(pi > 200) lvv = tl + tx;
   else lvv = lvl;
     if(lvv > 40) lvv = 40;
     if(lvv * heal_var[1] > castee->query_sp()) { tell_object(castee,"You are low on energy.\n"); return 1; }
     if(heal_var[2] > castee->query_hp()) { tell_object(castee,"You are low on physical energy.\n"); return 1; }
     if(heal_var[3] > castee->query_exp()) { tell_object(castee,"You are low on exp.\n"); return 1; }
     if(heal_var[4] > castee->query_money()) { tell_object(castee,"You are low on money.\n"); return 1; }
   if(targ->ShardakDragon()) return (tell_object(castee, "Impossible to heal such a beast.\n"), 1);
     castee->add_spell_point(-lvv * heal_var[1]);
     castee->add_hit_point(-heal_var[2]);
     if(hob) castee->add_xp(-heal_var[3]); else castee->add_exp(-heal_var[3]);
     castee->add_money(-heal_var[4]);
     if(!check(lvl,pi,heal_var[6],heal_var[7],heal_var[8])) {
     tell_object(castee,"Your healing fails!\n");
   return 1; }
  /* 05/26/06 Earwax: adjusted this from XX += lvv/10 to: */
  XX += lvv/7;
     hpm = targ->query_mhp() - targ->query_hp();
     spm = targ->query_msp() - targ->query_sp();
     if((hpm + spm) < 1) { tell_object(castee, targ->query_name()+" is fully healed.\n"); return 1; }
     if(pi > 200) HV = lvl * heal_var[5]; else HV = lvl * heal_var[5]*4/5 + random(lvl * heal_var[5]/5);
	 if(healamount) if(HV > healamount) HV = healamount;
	 if(HV < hpm) hpm = HV;
     if(HV < spm) spm = HV;
     if(!query_ip_name(targ)) { hpm /= 4; spm = 0; }
/********* Begin Changes ****************
   Change made here by Maledicta
   Keeps Sps from being added in when healing self,
   which thereby keeps the cost at a legal level.
*/
   if(typ != "hp" && typ != "sp"){
     if(targ != castee){
      if(!targ->heal_self(HV)) ok = 1;
      }
     else{
      if(!targ->add_hit_point(HV)) ok = 1;
      }
    }
/***** End Changes ***********************/
   if(typ == "hp") if(!targ->add_hit_point(HV)) ok = 1;
  if(typ == "sp") if(!targ->add_spell_point(HV)) ok = 1;
   if(ok) {
   if(hob && targ != castee && !present("mythos_healer",targ) &&
     targ->query_real_name() != "guest") {
   if(typ != "hp")
   castee->add_xp(spm * XX);
   if(typ != "sp")
     castee->add_xp(hpm * XX);
   }
   tell_object(castee,"You lay your hands on "+who+" and heal "+targ->query_objective()+"  ("+hpm+"/"+spm+" hp/sp amount)\n");
   say(castee->query_name()+" lays "+castee->query_possessive()+" hands on "+capitalize(who)+".\n");
   tell_object(targ,"You feel better.\n");
  }
 return 2; }
