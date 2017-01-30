
dark_prayer(string str){
  object comp;
  if(User->query_ghost()) return 0;
  if(!PO->query_skills("dark prayer")) return 0;
  if(PO->light_check()) return 1;
  if(!str) return 0;
  if(str != "prayer") return 0;
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
  if(!comp->query_bpowder())
  {
    TOU"You lack the spell component to cast this spell.\n");
    return 1;
  }
  if(!PO->spell_failure(3)) return 1;
  if(PO->casting_check()) return 1;
  if((int)User->query_spell_point() > 45)
  {
    TOU
      "You cup some bone powder in your hands and chant softly...\n"+
      "You try to cast the spell, but realize you are too strong...\n");
    comp->use_bpowder();
    User->add_hit_point((int)User->query_hp() / 4 * -1);
    return 1;
  }
  if((int)User->query_spell_point() <= 45 && 
    (int)User->query_spell_point() >= 0)
  {
    TOU
      "You cup some bone powder in your hands and chant softly...\n"+
      "You are lifted off the ground as shadows wrap around you...\n"+
      "Giving up your strength, you are filled with life energy...\n");
    TRU User->query_name()+" whispers a dark prayer.\n", ({User}));
    comp->use_bpowder();
    User->add_hit_point((int)User->query_hp() / 4 * -1);
    User->add_spell_point((int)User->query_mhp() / 2);
    PO->add_endurance(2);
    PO->energy_check();
    return 1;
  }
  return 1;
}
