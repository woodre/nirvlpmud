
shadowring(string str){
object target, web, comp;
  if(User->query_ghost()) return 0;
  if(!PO->query_skills("web")) return 0;
  if(PO->light_check()) return 1;
  if(!str && User->query_attack())
    target = User->query_attack();
  else if(str)
    target = present(str, environment(User));
  else return 0;
  if(!target){
    TOU"You don't see "+str+" here.\n");
    return 1;
  }
  if(!target->query_npc())
  {
    TOU"You cannot attack that.\n");
    return 1;
  }
  comp = present("guild_comp_pouch", User);
  if(environment(User)->realm() == "NM")
  {
    TOU"Your power is being drained here.\n");
    return 1;
  }
  if(!comp)
  {
    TOU"You lack the spell component to cast this spell.\n");
    return 1;
  }
  if(!comp->query_web())
  {
    TOU"You lack the spell component to cast this spell.\n");
    return 1;
  }
  if(target->ringed())
  {
    TOU"You may not cast this again on "+target->QN+".\n"); 
    return 1; 
  }
  if(!PO->spell_failure(2)) return 1;
  if(PO->casting_check()) return 1;

  TOU "You whisper a soft incantation...\n"+
    "You throw the spiders web at "+target->QN+"...\n"+
    "The web turns into a web of shadows, trapping "+target->QN+".\n");
  TRU User->QN+" throws a web of shadows on "+target->QN+".\n", ({User}));
  User->add_spell_point(-40);
  User->add_hit_point(-10);
  comp->use_web();
  web = clone_object("/players/zeus/circle/OBJ/shadowring.c");
  web->set_time(10 + PO->query_guild_exp()/200000);
  web->shadowring(target);
  PO->add_endurance(-5);
  PO->energy_check();
  return 1;
}

