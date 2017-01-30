
descend(str){
  int nt;
  object nmy;
  if(!GOB->query_skills("descend")) return 0;  
  if(User->query_ghost()) return 0;
  if(GOB->light_check()) return 1;
  if(!str && User->query_attack())
    nmy = User->query_attack();
  else if(str)
    nmy = present(str, environment(User));
  else if(!str && !User->query_attack())
    return 0;
  if(!nmy){
    TOU"You don't see "+str+" here.\n");
    return 1;
  }
  if(environment(User)->realm() == "NM")
  {
    TOU"Your power is being drained here.\n");
    return 1;
  }
  if(!living(nmy)){
    TOU"You cannot attack "+str+"!\n");
    return 1;
  }
  if(User->query_attack())
  {
    TOU"You can not perform this while in combat.\n");
    return 1;
  }
  if(nmy->is_player() && !nmy->query_pl_k())
  {
    if(!nmy->query_fight_area())
    {
      TOU"You cannot attack "+str+"!\n");
      return 1;
    }
  }
  if(GOB->casting_check()) return 1;
  if(random(User->query_attrib("ste")) <= 1)
  {
    TOU"You descend upon "+nmy->QN+" from the shadows...\n"+
      "However "+nmy->QN+" turns and blocks your attack!\n");
    TRU User->QN+" descends upon "+nmy->QN+" from the shadows.\n",
      ({ User }));
    User->add_spell_point(-15-random(11));
    nmy->attack_object(User);
    return 1;
  }
  TOU"You descend upon "+nmy->QN+" from the shadows...\n"+
    "You strike "+nmy->QN+" swiftly with shadow force!\n");
  TRU User->QN+" descends upon "+nmy->QN+" from the shadows.\n",
    ({ User }));
  nt = (int)GOB->query_guild_exp() / 300000;
  if(nt > 26) 
    nt = 26;
  User->add_spell_point(-15-random(11));
  nmy->hit_player(10+random(nt));
  User->attack_object(nmy);
  GOB->add_endurance(8 - (GOB->query_guild_exp() / 1000000));
  GOB->energy_check();
  return 1;
}
