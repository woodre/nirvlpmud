
vanish(){
  object comp, x, hook, room;
  string area;
  int mana;
  if(User->query_ghost()) return 0;
  if(!PO->query_skills("vanish")) return 0;
  if(PO->light_check()) return 1;
  comp = present("guild_comp_pouch", User);
  if(!comp)
  {
    TOU"You lack the spell component to cast this spell.\n");
    return 1;
  }
  if(!comp->query_pearl())
  {
    TOU"You lack the spell component to cast this spell.\n");
    return 1;
  }
  if(User->query_attack())
  {
    TOU"You can not perform this while in combat.\n");
    return 1;
  }
  if(environment(User)->realm() == "NM")
  {
    TOU"Your power is being drained here.\n");
    return 1;
  }
/*
  if(environment(User)->realm() == "NT")
  {
    TOU"You can not perform this here.\n");
    return 1;
  }
*/
  if(environment(User)->no_hiding()){
    write("You can not perform this here.\n");
    return 1;
  }
  if(!PO->spell_failure(2)) return 1;
  if(PO->casting_check()) return 1;

  TOU"You grasp the pearl in your hand and chant softly...\n"+
    "The shadows swirl up around you, engulfing your body...\n"+
    "The shadows calm as darkness encases you...\n\n"+
    "You can 'reappear' whenever you want.\n");

  area = file_name(environment(this_player()));
  x = clone_object("/players/zeus/circle/OBJ/vanish_room.c");
  if(sscanf(area, "%s#", room)){}
  else if(sscanf(area, "%s", room)){}
  else return 0;
  x -> set_exit(room);
  hook = clone_object("/players/zeus/circle/OBJ/vanish_hook.c");
  move_object(hook, environment(User));
  x -> set_hook(hook);
  move_object(clone_object("/players/zeus/circle/OBJ/vanish_obj.c"), User);
  comp->use_pearl();
  mana = (int)User->query_sp();
  User->add_spell_point((mana * -1) + 15);
  move_object(User, x);
  PO->add_endurance(-10);
  PO->energy_check();
  return 1;
}

