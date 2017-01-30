
beckon(str){
  object it;
  int dur;
  if(!GOB->query_skills("beckon shadows")) return 0;
  if(User->query_ghost()) return 0;
  if(GOB->light_check()) return 1;
  if(str != "shadows") return 0;
  if(environment(User)->realm() == "NM")
  {
    TOU"Your power is being drained here.\n");
    return 1;
  }
  if(!GOB->spell_failure(1)) return 1;
  if(GOB->casting_check()) return 1;

  TOU "You wave your hand beckoning shadows to fill the room.\n");
  TRU User->QN+" beckons shadows to fill the room.\n", ({User}));

  dur = 10 + ((int)GOB->query_guild_exp() / 200000);
  if(dur > 38) dur = 38;

  if(it = present("zeus_shad_ob", environment(User))){}
  else { it = clone_object("/players/guilds/fallen/OBJ/shadows.c");
         move_object(it, environment(User)); }
  it -> set_dur(dur);
  it -> set_own(User);

  User->add_spell_point(-dur);
  if(dur > 30) User->add_spell_point(-(dur / 2));
  GOB->energy_check();
  return 1;
}
