 fortify(int lvl,int pi,string who) {
  object targ, target_gob;
  /* Target and legality checks */
  if(!who) { write("Who do you wish to fortify?\n"); return 1; }
  if(!(targ=find_player(who))) { write("That person is not in game!\n"); return 1; }
  if(targ == tp) { write("You may not cast this on yourself!\n"); return 1; }
  if(targ->query_invis() > tl) { write("That person is not here!\n"); return 1; }
  if(targ->query_ghost()) { write("You can not cast upon a ghost!\n"); return 1; }
  if(targ->query_level() > 19)  { write("You can not cast upon a wiz!\n"); return 1; }
  if(!(target_gob=present(GUILD_OB_ID,targ))) { write("That person is not a healer.\n"); return 1; }
  /* Spell Cost Check */
  if(fortify_var[1] > tsp) { write("You are low on energy.\n"); return 1; }
  if(fortify_var[2] > thp) { write("You are low on physical energy.\n"); return 1; }
  if(fortify_var[3] > tp->query_exp()) { write("You are low on exp.\n"); return 1; }
  if(fortify_var[4] > tp->query_money()) { write("You are low on money.\n"); return 1; }
  /* Spell Cost Deduction */
  tp->add_spell_point(-fortify_var[1]);
  tp->add_hit_point(-fortify_var[2]);
  if(hob) tp->add_xp(-fortify_var[3]); else tp->add_exp(-fortify_var[3]);
  tp->add_money(-fortify_var[4]);
  /* Spell Failure */
  if(!check(lvl,pi,fortify_var[6],fortify_var[7],fortify_var[8])) { 
    write("Your fortify fails!\n");
    return 1; 
  }
  target_gob->add_fortify(lvl);
  write("You close your eyes and pray for moment.  You have fortified "+capitalize(targ->query_real_name())+"\n");
  say(tp->query_name()+" closes "+tp->query_possessive()+" eyes and intones for a moment.\n");
  tell_object(targ,tp->query_name()+" fortifies you!  Your next heal has been given a boost.\n");
  return 1; 
 }