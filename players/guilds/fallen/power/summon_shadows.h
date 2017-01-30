
summon(string str){
  object comp;
  if(User->query_ghost()) return 0;
  if(!GOB->query_skills("summon shadows")) return 0;
  if(GOB->light_check()) return 1;
  if(!str || str != "shadows") return 0;
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
  if(!comp->query_obsidian() || !comp->query_oil())
  {
    TOU"You lack the spell component to cast this spell.\n");
    return 1;
  }
  if(GOB->casting_check()) return 1;
  TOU
    "You kneel to the ground and digging a small depression,\n"+
    "place a fragment of obsidian into the hole.  You begin\n"+
    "to chant as you pour your energy into the obsidian...\n\n");
  TRU
    User->QN+" digs a hole in the ground and places something inside.\n"+
    "Kneeling, "+User->QN+" begins to chant.\n", ({ User }));
  comp->use_obsidian();
  User->add_spell_point(-(User->query_msp() / 2));
  move_object(clone_object(
    "/players/guilds/fallen/OBJ/summon_tendrils.c"), User);
  GOB->add_endurance(-(20 + random(16)));
  GOB->energy_check();
  return 1;
}
