
weaken(str)
{
  object target, obj;
  if(!PO->query_skills("weaken")) return 0;
  if(User->query_ghost()) return 0;
  if(PO->light_check()) return 1;
  if(!str && User->query_attack())
    target = User->query_attack();
  else if(str)
    target = present(str, environment(User));
  else if(!str && !User->query_attack())
    return 0;
  if(!target)
  {
    TOU"You don't see "+str+" here.\n");
    return 1;
  }
  if(target->is_player())
  {
    TOU"You cannot weaken "+str+"!\n");
    return 1;
  }
  if(environment(User)->realm() == "NM")
  {
    TOU"Your power is being drained here.\n");
    return 1;
  }
  if(!PO->spell_failure(1+random(2))) return 1;
  if(PO->casting_check()) return 1;

  TOU BOLD+BLK+
    "You conjure up the shadows to weaken "+target->QN+".\n"+NORM);
  TRU BOLD+BLK+User->QN+
    " conjures up the shadows to weaken "+target->QN+".\n"+NORM, ({User}));
  obj = present("weaken_counter", target);
  if(!obj)
    move_object(clone_object("/players/zeus/circle/OBJ/weaken.c"), target);
  else if(obj)
    obj->weaken(1);
  User->add_spell_point(-15-random(10));
  PO->add_endurance(-1);
  PO->energy_check();
  return 1;
}
