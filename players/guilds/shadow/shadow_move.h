shadow_move(dest_dir)
{
  int amode, loseShadowsChance;
  string dir, dest;
  object gob;
  gob = present("shadow-mark", player);

  if (!check_shadows())
  {
    player->move_player(dest_dir);
    return;
  }

  if (!dest_dir)
  {
    write("No destdir.\n");
    return;
  }

  if (sscanf(dest_dir, "%s#%s", dir, dest) != 2)
  {
    write("Bad movement.\n");
    return;
  }

/* fix this for increased stats. -Bp */
  if(player->query_attrib("ste") < 21)
  if(random(30) > total_stealth() - gob->shadows_modifier())
  {
    write("You step out of the shadows by mistake.\n");
    gob->set_shadows(0);
    player->move_player(dest_dir); return;
  }
  else 
  if(random(40) > total_stealth() - gob->shadows_modifier())
  {
    write("You step out of the shadows by mistake.\n");
    gob->set_shadows(0);
    player->move_player(dest_dir); return;
  }

  move_object(player, dest);

  amode = (int)gob->query_attack_mode();
  loseShadowsChance = 10;
  if      (amode == 1) loseShadowsChance = 20;
  else if (amode == 2) loseShadowsChance =  2;
  gob->add_shadows_modifier(loseShadowsChance);

  command("look", player);
  return 1;
}


total_stealth()
{
  int stealth, rank;
  stealth = player->query_attrib("ste");
  rank = present("shadow-mark", player)->guild_lev();
  return stealth+rank;
}
