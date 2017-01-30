
embrace(str)
{
  object target, obj;
  if(User->query_ghost()) return 0;
  if(!PO->query_skills("embrace")) return 0;
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
    TOU"You cannot embrace "+str+"!\n");
    return 1;
  }
  if(environment(User)->realm() == "NM")
  {
    TOU"Your power is being drained here.\n");
    return 1;
  }
  if(!present("weaken_counter", target))
  {
    TOU target->QN+" is too strong.\n");
    return 1;
  }
  if(!PO->query_focus())
  {
    TOU "Your focus of the shadows is too weak.\n");
    return 1;
  }
  if(present("shadow_embrace_object", target))
  {
    TOU target->QN+" has already been embraced by shadows.\n");
    return 1;
  }
  if(!PO->spell_failure(2)) return 1;
  if(PO->casting_check()) return 1;

  obj = clone_object("/players/zeus/circle/OBJ/embrace.c");
  
  TOU "You slide through the shadows towards "+target->query_name()+"...\n"+
    "You wrap your arms around "+target->query_possessive()+" head...\n"+
    BOLD+BLK+"Shadows begin to pour into "+target->query_name()+"!\n"+NORM);

  TRU BOLD+BLK+User->query_name()+" embraces "+target->QN+"'s head as "+
    "shadows pour into "+target->query_possessive()+"!\n"+NORM, ({ User }));

  obj->set_objects(User, User); /* changed to work with new embrace.c obj */
  move_object(obj, target);
  User->add_spell_point(-100);
  PO->add_endurance(-6);
  PO->set_casting(4);
  PO->energy_check();
  return 1;
}
