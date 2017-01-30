/* Original code by Mythos
   Updated by Illarion Aug 2009
 */
heal(int lvl, int pi, string who, string heal_type, int entered_heal_amount, int multp, object caster) {
  object targ, guild_object;
  int casting_level, ok, exp_multiplier;
  int sp_healed, hp_healed, heal_amount;
  int casting_cost;
  int fortify_amount;

  ok = sp_healed = hp_healed = 0;
  exp_multiplier = 5 + random(3);

  if(!caster) { 
    caster = this_player(); 
  }
  if(multp) exp_multiplier = exp_multiplier + multp;
  if(!who) { tell_object(caster,"Who do you wish to heal?\n"); return 1; }
  if(!(targ=present(who,environment(caster)))) {
    tell_object(caster,"That person is not here!\n");
    return 1; 
  }
  /* Spell Legality and Sanity Check */
  if(!living(targ)) { tell_object(caster,"You may only cast upon something living.\n"); return 1; }
  if(targ->query_invis() > tl) { tell_object(caster,"That person is not here!\n"); return 1; }
  if(targ->query_ghost()) { tell_object(caster,"You can not cast upon a ghost!\n"); return 1; }
  if(targ->query_level() > 19 && targ->is_player())  { tell_object(caster,"You can not cast upon a wiz!\n"); return 1; }
  if(targ->query_real_name() == "guest") { tell_object(caster,"Guest may not be healed.\n"); return 1; }
  if(targ->ShardakDragon()) return (tell_object(caster, "Impossible to heal such a beast.\n"), 1);
  
  /* Calculate power and cost */
  casting_level = lvl;
  guild_object = present(GUILD_OB_ID,tp);
  if(guild_object) {
    fortify_amount = guild_object->query_fortify();
    casting_level+= fortify_amount;
  }
  if(casting_level > 40) casting_level=40+((casting_level-40)/5);
  
  casting_cost = casting_level * heal_var[1];
  if(heal_type != "heal") casting_cost /= 2;
  if(casting_cost > caster->query_sp()) { tell_object(caster,"You are low on energy.\n"); return 1; }
  if(heal_var[2] > caster->query_hp()) { tell_object(caster,"You are low on physical energy.\n"); return 1; }
  if(heal_var[3] > caster->query_exp()) { tell_object(caster,"You are low on exp.\n"); return 1; }
  if(heal_var[4] > caster->query_money()) { tell_object(caster,"You are low on money.\n"); return 1; }

  hp_healed = targ->query_mhp() - targ->query_hp();
  sp_healed = targ->query_msp() - targ->query_sp();
  if((hp_healed + sp_healed) < 1) { tell_object(caster, targ->query_name()+" is fully healed.\n"); return 1; }

  
  /* Spell Cost Deduction */
  caster->add_spell_point(-casting_cost);
  write("You have expended "+casting_cost+" SP.\n");
  caster->add_hit_point(-heal_var[2]);
  if(guild_object) 
    caster->add_xp(-heal_var[3]); 
  else 
    caster->add_exp(-heal_var[3]);
  caster->add_money(-heal_var[4]);
  /* Spell Failure (extra chance of success for each fortify) */
  if(!check(lvl,pi+(fortify_amount*2),heal_var[6],heal_var[7],heal_var[8])) {
    tell_object(caster,"Your healing fails!\n");
    return 1; 
  }
  /* Calculation of healing amount */
  exp_multiplier += casting_level/7;
  if(fortify_amount > 0) 
    heal_amount = casting_level * heal_var[5]; 
  else 
    heal_amount = casting_level * heal_var[5]*4/5 + random(casting_level * heal_var[5]/5);
  if(entered_heal_amount < 0) {
    write("Your attempt to heal for a negative value has been automatically fixed.\n");
    entered_heal_amount = -entered_heal_amount;
  }
	if(entered_heal_amount && heal_amount > entered_heal_amount) 
    heal_amount = entered_heal_amount;
	if(heal_amount < hp_healed) hp_healed = heal_amount;
  if(heal_amount < sp_healed) sp_healed = heal_amount;
  if(!query_ip_name(targ)) { 
    write("You feel most of your energy being rejected.");
    hp_healed /= 4; 
    sp_healed = 0; 
  }
  if(heal_type == "heal" && targ == caster) {
    write("You switch your efforts to healing energies.");
    heal_type="hp";
  }
  if(heal_type == "heal" && !targ->heal_self(heal_amount)) ok = 1;
  else if(heal_type == "hp" && !targ->add_hit_point(heal_amount)) ok = 1;
  else if(heal_type == "sp" && !targ->add_spell_point(heal_amount)) ok = 1;
  /* Add xp for healing */
  if(ok) {
    if(guild_object && targ != caster && !present("mythos_healer",targ)) {
      if(heal_type != "hp")
        caster->add_xp(sp_healed * exp_multiplier);
      if(heal_type != "sp")
        caster->add_xp(hp_healed * exp_multiplier);
      guild_object->consume_fortify();
    }
    tell_object(caster,"You lay your hands on "+who+" and heal "+targ->query_objective()
    +"  ("+(heal_type!="sp"?hp_healed:0)+"/"+(heal_type!="hp"?sp_healed:0)+" hp/sp amount)\n");
    say(caster->query_name()+" lays "+caster->query_possessive()+" hands on "+capitalize(who)+".\n");
    tell_object(targ,"You feel better.\n");
  } else {
    caster->add_spell_point(casting_cost/2);
    write("You recover some of your lost energy.\n");
  }
  return 2; 
}
