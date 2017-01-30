

dark_assistance_spell(){
  object enemy, alt_enemy;
  int w, x, y, z, big, msg;
  if(USER->query_ghost()) return;
  enemy = USER->query_attack();
  alt_enemy = USER->query_alt_attack();
  w = random(4);
  x = random(5);
  y = random(5);
  z = random(3);
  big = random(25);
  if(guild_exp > 5200000 && random(guild_exp / 2600000) > 0)
    endurance += 1;
  if(!w)
  {
    msg = random(4);
    enemy->heal_self(-2);
    switch(msg)
    {
    case 0:
      tell_room(environment(USER),
        BOLD+BLK+"Darkness swirls around "+USER->QN+".\n"+NORM, ({USER}));
      tell_object(USER, BOLD+BLK+
        "Darkness swirls around you.\n"+NORM);
      break;
    case 1:
      tell_room(environment(USER), BOLD+BLK+
        "The darkness pulses around "+USER->QN+".\n"+NORM, ({USER}));
      tell_object(USER, BOLD+BLK+
        "The darkness pulses around you.\n"+NORM);
      break;
    case 2:
      tell_room(environment(USER), BOLD+BLK+
        USER->QN+" is covered in dark energy.\n"+NORM, ({USER}));
      tell_object(USER, BOLD+BLK+
        "You are covered in dark energy.\n"+NORM);
      break;
    case 3:
      tell_room(environment(USER), BOLD+BLK+
        "Dark energy pours from "+USER->QN+".\n"+NORM, ({USER}));
      tell_object(USER, BOLD+BLK+
        "Dark energy pours from you.\n"+NORM);
      break;
    }
  }
  else if(!x)
  {
    msg = random(3);
    enemy->heal_self(-3-random(4));
    switch(msg)
    {
    case 0:
      tell_room(environment(USER), BOLD+BLK+
        "Strands of darkness pour through "+enemy->QN+".\n"+NORM, ({enemy}));
      tell_object(enemy, BOLD+BLK+
        "Strands of darkness pour through you.\n"+NORM);
      break;
    case 1:
      tell_room(environment(USER), BOLD+BLK+
        "Invisible forces pull at "+enemy->QN+".\n"+NORM, ({enemy}));
      tell_object(enemy, BOLD+BLK+
        "Invisible forces pull at your body.\n"+NORM);
      break;
    case 2:
      tell_room(environment(USER), BOLD+BLK+enemy->QN+
        " is knocked back by an invisible force.\n"+NORM,({enemy}));
      tell_object(enemy, BOLD+BLK+
        "You are knocked back by an invisible force.\n"+NORM);
      break;
    }
  }
  else if(!y)
  {
    msg = random(3);
    switch(msg)
    {
    case 0:
      tell_room(environment(USER), BOLD+BLK+
        "Darkness suddenly envelops "+USER->QN+".\n"+NORM, ({USER}));
      tell_object(USER, BOLD+BLK+
        "Darkness suddenly envelops you.\n"+NORM);
      USER->add_spell_point(2+random(3));
      break;
    case 1:
      tell_room(environment(USER), BOLD+BLK+USER->QN+
        " writhes in dark energy.\n"+NORM, ({USER}));
      tell_object(USER, BOLD+BLK+
        "You writhe in dark energy.\n"+NORM);
      USER->add_spell_point(1+random(5));
      break;
    case 2:
      tell_room(environment(USER), BOLD+BLK+
        "Waves of darkness pour over "+USER->QN+".\n"+NORM, ({USER}));
      tell_object(USER, BOLD+BLK+
        "Waves of darkness pour over your.\n"+NORM);
      USER->add_spell_point(1+random(4));
      break;
    }		
  }
  if(!z && alt_enemy)
  {
    msg = random(3);
    alt_enemy->heal_self(-2-random(4));
    switch(msg)
    {
    case 0:
      tell_room(environment(USER), BOLD+BLK+
        "Dark energy tears at "+alt_enemy->QN+".\n"+NORM, ({alt_enemy}));
      tell_object(alt_enemy, BOLD+BLK+
        "Dark energy tears at you.\n"+NORM);
      break;
    case 1:
      tell_room(environment(USER), BOLD+BLK+
        "Strands of darkness fly at "+alt_enemy->QN+".\n"+NORM,({alt_enemy}));
      tell_object(alt_enemy, BOLD+BLK+
        "Strands of darkness fly at you.\n"+NORM);
      break;
    case 2:
      tell_room(environment(USER), BOLD+BLK+alt_enemy->QN+
        " is engulfed in dark energy.\n"+NORM, ({alt_enemy}));
      tell_object(alt_enemy, BOLD+BLK+
        "You are engulfed in dark energy.\n"+NORM);
    }
  }
  if(!big)
  {
    tell_room(environment(USER), RED+
      "\nFlames of Darkness "+NORM+"explode from "+USER->QN+"...\n"+
      BOLD+BLK+enemy->QN+" writhes in burning agony!\n\n"+NORM, ({enemy}));
    tell_object(enemy,
      RED+"\nFlames of Darkness "+NORM+"explode from "+USER->QN+"...\n"+
      BOLD+BLK+"You writhe in burning agony!\n\n"+NORM);
    enemy->heal_self(-5-random(20));
  }
  if(present("weaken_counter", enemy))
    enemy->heal_self(-1);
}

