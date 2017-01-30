
shadowform(){
  object comp, room, form;
  string longdesc;
  int x;
  comp = present("guild_comp_pouch", User);
  if(User->query_ghost()) return 0;
  if(!PO->query_skills("shadowform")) return 0;
  if(PO->light_check()) return 1;
  if(environment(User)->realm() == "NM")
  {
    TOU"Your power is being drained here.\n");
    return 1;
  }
  if(!comp){
    TOU "You lack the spell component to cast this spell.\n");
    return 1;
  }
  if(!comp->query_blossom()){
    TOU "You lack the spell component to cast this spell.\n");
    return 1;
  }
  if((int)User->query_spell_point() < 50){
    TOU
      "You feel too drained to cast this now.\n");
    return 1;
  }
  if(!User->query_attack()){
    TOU "This may only be cast while in combat.\n");
    return 1;
  }
  if(!PO->spell_failure(3)) return 1;
  if(PO->casting_check()) return 1;

  longdesc = BOLD+BLK+
    "This is a mindless being of the shadows...\n"+
    "It appears almost entirely real...\n"+NORM;

  TOU"You grasp the ash blossom in you hand and whisper an incantation...\n"+
    "Shadows pulse around you, creating a shadowform of yourself...\n");
  TRU User->QN+" whispers a soft incantation.\n", ({User}));

  form = clone_object("/obj/monster");
  form->set_name(User->query_real_name());
  form->set_short(User->short());
  form->set_long(longdesc);
  form->set_info("zeus_shadowform");
  form->set_ac(1);
  form->set_hp(5+random(50));
  form->set_level(1);
  form->set_wc(1);
  move_object(form, environment(User));
  move_object(clone_object(
    "/players/zeus/circle/OBJ/shadowform.c"), form);

  User->stop_fight();
  room = all_inventory(environment(User));
  for(x = 0; x < sizeof(room); x++){
    if(room[x]->query_alt_attack() == User || room[x]->query_attack() == User)
    {
      room[x]->stop_fight();
      room[x]->stop_fight();
      room[x]->attack_object(form);
    }
  }
  User->stop_fight();
  User->stop_hunter();
  comp->use_blossom();
  User->add_hit_point(-10);
  User->add_spell_point(-50);
  PO->add_endurance(-5);
  PO->energy_check();
  return 1;
}
