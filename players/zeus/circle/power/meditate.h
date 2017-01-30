
meditate(){
  object corpse, corpse2;
  string extra;
  if(User->query_ghost()) return 0;
  if(!PO->query_skills("meditate")) return 0;
  if(PO->light_check()) return 1;
  corpse = present("corpse", environment(User));
  corpse2 = present("corpse", environment(PO));  
  if(!corpse && !corpse2)
  {
    TOU"There is no corpse present.\n");
    return 1;
  }
  if(!PO->spell_failure(4)) return 1;
  if(PO->casting_check()) return 1;
  TOU
    "You kneel before the corpse, placing your hands on it.\n"+
    "Shadows swirl around you as you focus your power...\n\n");
  TRU
    User->QN+" kneels before the corpse.\n", ({ User }));
  if(!corpse2)
  {
    if (sscanf(file_name(corpse),"obj/corpse%s",extra)!=1) return 1;
    User->add_spell_point((int)corpse->query_corpse_level() / 2);
    destruct(corpse);
  }
  else
  {
    if (sscanf(file_name(corpse2),"obj/corpse%s",extra)!=1) return 1;
    User->add_spell_point((int)corpse2->query_corpse_level() / 2);
    destruct(corpse2);
  }
  move_object(clone_object(
    "/players/zeus/circle/OBJ/meditate_obj.c"), User);
  PO->add_endurance(2);
  return 1;
}
