
repulsion(){
  object room, comp;
  int x, number, damage;
  if(User->query_ghost()) return 0;
  if(!GOB->query_skills("repulsion")) return 0; 
  if(GOB->light_check()) return 1;
  number = 0;
  room = all_inventory(environment(User));
  comp = present("guild_comp_pouch", User);
  if(environment(User)->realm() == "NM")
  {
    TOU"Your power is being drained here.\n");
    return 1;
  }
  if(!User->query_attack())
  {
    TOU"You cannot cast this at this time.\n");
    return 1;
  }
  if(!comp){
    TOU"You lack the spell component to cast this spell.\n");
    return 1;
  }
  if(!comp->query_leaf()){
    TOU"You lack the spell component to cast this spell.\n");
    return 1;
  }
  if(!GOB->spell_failure(3)) return 1;
  if(GOB->casting_check()) return 1;
  for(x = 0; x < sizeof(room); x++){
    if(room[x]->query_attack() == User)
      number += 1;
  }
  if(number >= 2){
    TOU
"You grasp the black leaf in your fist and raise it towards the sky...\n"+
"A wave of dark shadow energy explodes out from your hand...\n"+
"Your enemies stagger back, stunned by the blow...\n");
    TRU User->QN+" raises "+User->POS+" fist towards the sky...\n"+
"A wave of dark shadow energy explodes outwards...\n", ({User}));
    User->stop_fight();
    for(x = 0; x < sizeof(room); x++){
      if(room[x]->query_alt_attack() == User ||
        room[x]->query_attack() == User){
        damage = 10 + random((GOB->query_guild_exp() / 130000) + 10);
        if(damage > 43) damage = 43;
        room[x]->hit_player(damage);
      }
    }
    room = all_inventory(environment(User));
    for(x = 0; x < sizeof(room); x++){
      if(room[x]->query_alt_attack() == User ||
        room[x]->query_attack() == User){
        room[x]->stop_fight();
        room[x]->stop_fight();
        room[x]->stop_hunter();
      }
    }
    User->stop_fight();
    User->stop_hunter();
    comp->use_leaf();
    User->add_hit_point((int)User->query_hp() * 3 / 4 * -1);
    User->add_spell_point(-((int)User->query_spell_point()) + 15);
    GOB->add_endurance(-10);
    GOB->energy_check();
    return 1;
  }
  else if(number < 2)
  {
    TOU"You cannot cast this at this time.\n");
    return 1;
  }
  else return 0;
  return 1;
}

