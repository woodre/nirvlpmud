
dark_assistance()
{
  object comp;
  comp = present("guild_comp_pouch", User);
  if(User->query_ghost()) return 0;
  if(!PO->query_skills("dark assistance")) return 0;
  if(PO->light_check()) return 1;
  if(environment(User)->realm() == "NM")
  {
    TOU"Your power is being drained here.\n");
    return 1;
  }
  if(!comp)
  {
    TOU "You lack the spell component to cast this spell.\n");
    return 1;
  }
  if(!comp->query_root())
  {
    TOU "You lack the spell component to cast this spell.\n");
    return 1;
  }
  if(!PO->spell_failure(3)) return 1;
  if(PO->casting_check()) return 1;
  
  TOU "You whisper a dark incantation as you hold the root...\n"+
    "Shadows begin to swirl all across your body...\n");
  TRU User->query_name()+" whispers a dark incantation.\n", ({User}));

  User->add_spell_point(-150);
  User->add_hit_point(-25);
  comp->use_root();
  PO->set_dark_ass(3);
  PO->add_endurance(-5);
  PO->energy_check();
  return 1;
}
