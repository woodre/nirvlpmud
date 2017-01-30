
teleport(str){
  string doh, area, strr;
  int path, road, guth, a,b,c;
  object ob, comp, room;
  if(User->query_ghost()) return 0;
  if(!GOB->query_skills("teleport")) return 0;
  if(GOB->light_check()) return 1;
  path = 1 + random(23);
  road = 1 + random(7);
  guth = 1 + random(18);
  c = 0;
  comp = present("guild_comp_pouch", User);
  if(str == "help")
  {
    tell_object(User, 
      "No argument will teleport you to a random room in the Fallen Lands.\n"+
      "You can not teleport while wearing armor.  You can teleport from\n"+
      "any room within the Fallen Lands, except the mist.  Valid locations:\n\n"+
      "  1> Guild hall\n"+
      "  2> Tyborlek\n"+
      "  3> Blacksmith\n"+
      "  4> Druid\n"+
      "  5> Old Gurther\n"+
      "  6> Auseth\n"+
      "  7> Demon Plane\n"+
      "\n");
    return 1;
  }
  if(!comp)
  {
    TOU"You lack the spell component to cast this spell.\n");
    return 1;
  }
  if(!comp->query_feather())
  {
    TOU"You lack the spell component to cast this spell.\n");
    return 1;
  }
  if(environment(User)->realm() == "NM")
  {
    TOU"Your power is being drained here.\n");
    return 1;
  }
  area = file_name(environment(User));
  if(!sscanf(area, "%splayers/zeus/realm/%s", room) &&
    environment(User)->realm() == "NT" || 
    (sscanf(area, "%splayers/zeus/realm/taus/circle%s", room)
    && environment(User)->realm() == "NT"))
  {
    TOU"You are unable to teleport from here.\n");
    return 1;
  }
  if(!GOB->spell_failure(1)) return 1;
  if(GOB->casting_check()) return 1;
  
  ob = all_inventory(User);
  b = sizeof(ob);
  for(a = 0; a < b; a++)
  {
    strr = call_other(ob[a], "query_worn");
    if(strr)
    {
      ob[a]->drop();
      move_object(ob[a], environment(User));
      c = 1;
    }
  }
  if(c)
    TOU"\n\n");

  User->recalc_carry();

  TOU"You hold forth a small crows feather and channel your magic\n"+
    "through the component.  A shadow folds in upon you...\n\n"+
    BOLD+BLK+"\t\tYour body soars.....\n\n\n"+NORM);
  User->add_spell_point(-35);
  if(!random(2))
  {
    if(doh = call_other("obj/base_tele","teleport"))
    {
      User->move_player("with an astonished look#"+doh);
      comp->use_feather();
      GOB->add_endurance(-5);
      GOB->energy_check();
      return 1;
    }
  }
  TRU User->QN+" concentrates briefly and vanishes into a shadow.\n",
    ({User}));
  if(str == "1" || str == "ghall" || str == "guild hall")
    move_object(User, "/players/guilds/fallen/rooms/ghall.c");
  else if(str == "2" || str == "tyborlek" || str == "tyb")
    move_object(User, "/players/zeus/realm/city/ent.c");
  else if(str == "3" || str == "blacksmith" || str == "smith")
    move_object(User, "/players/zeus/realm/taus/guth10.c");
  else if(str == "4" || str == "druid" || str == "grove")
    move_object(User, "/players/zeus/realm/taus/grove.c");
  else if(str == "5" || str == "old gurther" || str == "old")
    move_object(User, "/players/zeus/realm/taus/oldguth.c");
  else if(str == "6" || str == "auseth")
    move_object(User, "/players/zeus/realm/taus/tower6.c");
  else if(str == "7" || str == "demon plane" || str == "plane")
    move_object(User, "/players/zeus/realm/d/ent.c");
  else
  {
    c = random(3);
    switch(c)
    {
    case 0:
      move_object(User, "/players/zeus/realm/city/path"+path+".c");
      break;
    case 1:
      move_object(User, "/players/zeus/realm/taus/road"+road+".c");
      break;
    case 2:
      move_object(User, "/players/zeus/realm/taus/guth"+guth+".c");
      break;
    }
  }
  command("look", User);
  TRU User->QN+" appears suddenly from a shadow.\n", ({User}));
  comp->use_feather();
  GOB->add_endurance(-5);
  GOB->energy_check();
  return 1;  
}
