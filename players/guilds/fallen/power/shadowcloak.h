
shadowcloak(){
  if(User->query_ghost()) return 0;
  if(!GOB->query_skills("shadowcloak")) return 0;
  if(GOB->light_check()) return 1;
  if(GOB->query_shadowcloak())
  {
    command("visible", User);
    GOB->set_shadowcloak(0);
    return 1;
  }
  else if(User->query_invis()){
    TOU"You are already invisible.\n");
    return 1;
  }
  if(environment(User)->realm() == "NM")
  {
    TOU"Your power is being drained here.\n");
    return 1;
  }
  if(!GOB->spell_failure(2)) return 1;
  if(GOB->casting_check()) return 1;

  TOU"You wrap yourself in a cloak of shadows.\n"+
    "Type 'shadowcloak' to return from the shadows.\n");
  TRU User->QN+" vanishes in a cloak of shadows.\n", ({User}));
  User->add_spell_point(-40-random(15));
  User->set_invs_sp();
  GOB->set_shadowcloak(1);
  GOB->add_endurance(-3);
  GOB->energy_check();
  return 1;
}
