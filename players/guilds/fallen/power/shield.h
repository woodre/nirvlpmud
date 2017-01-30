
shield(){
  object it;
  int dur, val, gxp;
  if(User->query_ghost()) return 0;
  if(!GOB->query_skills("shield")) return 0;
  if(GOB->light_check()) return 1;
  if(environment(User)->realm() == "NM")
  {
    TOU"Your power is being drained here.\n");
    return 1;
  }
  if(!GOB->spell_failure(2)) return 1;
  if(GOB->casting_check()) return 1;

  if(GOB->query_sshield())
    TOU"You strengthen your shield of shadows.\n");
  else
  {
    TOU "You close your eyes and focus your mind...\n"+
      "You whisper and beckon as the shadows curl up around you...\n"+
      "The shadows form a shield to help protect you from harm.\n");
  }

  TRU User->QN+" beckons the shadows to help protect "+
    User->query_objective()+".\n", ({User}));

  gxp = ((int)GOB->query_guild_exp() / 800000);

  dur = 20 + (gxp);

  if(User->query_ac() < 2)
    dur += 2+random(4);
  else if(User->query_ac() < 3)
    dur += 1+random(3);
  else if(User->query_ac() < 5)
    dur += 1;

  GOB->set_sshield(dur);

          /* sps cost ranges from -30 to -80 */
  User->add_spell_point(-(30+(gxp * (3+random(3)))));
  User->add_hit_point(-5);
  GOB->add_endurance(-3);
  GOB->energy_check();
  return 1;
}
