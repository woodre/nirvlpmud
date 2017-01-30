/* 10/19/05 Earwax: Changed chances of coming out of shadows.
 *   These were incredibly high before - usually you can't even leave
 *   a room without pulling out of shadows, no matter what stats.
*/
shadow_move(dest_dir)
{
  int amode, loseShadowsChance;
  string dir, dest;
  object gob;
  gob = present(GUILD_ID, player);

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

/* fixed this for increased stats. -Bp */
  player->add_spell_point(-20);
  if(player->query_spell_point() < 0) {
    write("You step out of the shadows by mistake.\n");
    gob->set_shadows(0);
    player->move_player(dest_dir); return;
  }
  /* 10/19/05 Earwax: Adjusted this.  Ninja shadows virtually unusable
   * for the last year.
   * This check was 60
  */
  if(random(11) > total_stealth() - gob->shadows_modifier())
  {
    write("You step out of the shadows by mistake.\n");
    gob->set_shadows(0);
    player->move_player(dest_dir); return;
  }
  else 
  /* This check was random(70) */
  if(random(11) > total_stealth() - gob->shadows_modifier())
  {
    write("You step out of the shadows by mistake.\n");
    gob->set_shadows(0);
    player->move_player(dest_dir); return;
  }

  move_object(player, dest);

  /* Debating about changing these.  Stealth mode vs hyper that steep? */
  amode = (int)gob->query_attack_mode();
  loseShadowsChance = 15;
  if      (amode == 1) loseShadowsChance = 25;
  else if (amode == 2) loseShadowsChance =  8;
  gob->add_shadows_modifier(loseShadowsChance);

  command("look", player);
  return 1;
}


total_stealth()
{
  int stealth, rank;
  stealth = player->query_attrib("ste");
  rank = present(GUILD_ID, player)->guild_lev();
  return stealth+rank;
}
