
status empower(string str){
  object npc, comp, spell;
  if(User->query_ghost()) return 0;
  if(!GOB->query_skills("empower")) return 0;
  if(GOB->light_check()) return 1;
  if(!str) return 0;
  npc = present(str, environment(User));
  if((string)environment(User)->realm() == "NM")
  {
    TOU"Your power is being drained here.\n");
    return 1;
  }
  if(!npc)
  {
    TOU"There is no "+str+" here.\n");
    return 1;
  }
  if(!npc->is_npc())
  {
    TOU"You can not empower "+str+".\n");
    return 1;
  }
  comp = present("guild_comp_pouch", environment(previous_object()));
  if(!comp)
  {
    TOU"You lack the spell component to cast this spell.\n");
    return 1;
  }
  if(!comp->query_gem())
  {
    TOU"You lack the spell component to cast this spell.\n");
    return 1;
  }
  if(present("ruby_red_gem_damn", npc))
  {
    TOU"You can not cast this again on "+npc->QN+".\n");
    return 1;
  }
  if(!GOB->spell_failure(2)) return 1;
  if(GOB->casting_check()) return 1;

  TOU
    "Holding the gem in your hands, you whisper a dark chant...\n"+
    "A dark shadow begins swirling around the gem and "+npc->QN+"...\n"+
    "The gem vanishes as the shadow wraps around "+npc->QN+".\n");
  TRU User->QN+" whispers a dark chant...\n"+
    "A dark shadow swirls around "+npc->QN+".\n", ({User}));
  User->add_spell_point(-100);
  User->add_hit_point(-25);
  spell = clone_object("/players/guilds/fallen/OBJ/empower_spell.c");
  move_object(spell, npc);
  spell->set_empowered(1);
  comp->use_gem();
  GOB->add_endurance(-15);
  GOB->energy_check();
  return 1;
}
