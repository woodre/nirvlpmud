/*
  rip_throat.h - a deathblow type of spell
*/

rip_throat(str) {
  object target_obj;
  string target_name, msg;
  int target_hp, hp_percent, hp_max;

  /* mandated by mythos */
  hp_percent = 10;
  hp_max = 30;

  if (MY_PLAYER->query_ghost()) {
    write("How can you attack anything? You are a ghost.\n");
    return 1;
  }
  if (!str) {
    if (MY_PLAYER->query_attack() && MY_PLAYER->query_attack()->query_name()) {
      str = MY_PLAYER->query_attack()->query_name();
      if (!present(str, MY_ROOM)) str = 0;
    }
  }
  if (!str) str = MY_FANGS->query_target_name();
  if (!str) {
    write("You must specify who's throat you want to rip.\n");
    write("Use: rip [<who>]\n");
    return 1;
  }
  if (MY_LEVEL < 4 || MY_GUILD_EXP < 667) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  target_obj = present(str, MY_ROOM);
  if (!target_obj) {
    write("'"+str+"' is not here.\n");
    return 1;
  }
  if (MY_LEVEL < 21 && !target_obj->query_npc()) {
    write("You can't use guild spells against players anymore!\n");
    return 1;
  }
  target_name = capitalize(target_obj->query_name());
  target_hp = target_obj->query_mhp() / 10;
  /* target's hp must be <= max_hp and <= max_hp */
  if (target_obj->query_hp() > target_hp ||
      target_obj->query_hp() > hp_max) {
    write(target_name+" is too healthy to die in one stroke.\n");
    return 1;
  }
  if(MY_PLAYER->query_spell_point() < 2 * target_hp) {
  /* this is not random damage, must cost at least 2sp per point -Bp */
    write("You don't have enough spell points.\n");
    return 1;
  }
  write("You grab "+capitalize(str)+"'s shoulder with one hand and "+
        target_obj->query_possessive()+"\n"+
        " head with the other and bend them apart\n"+
        "to expose "+target_obj->query_possessive()+" neck, then you rip "+
        target_obj->query_possessive()+"\n"+
        " throat out!\n");
  msg = MY_NAME_CAP + " grabs "+capitalize(str)+"'s shoulder with one hand and "+
        target_obj->query_possessive()+"\n"+
        " head with the other and bends them apart to expose "+
        target_obj->query_possessive()+"\n"+
        " neck, then "+MY_PLAYER->query_pronoun()+" rips "+
        target_obj->query_possessive()+" throat out!\n";
  MY_FANGS->tell_my_room(msg);
  MY_PLAYER->add_spell_point(- 2 * target_hp);
  target_obj->attacked_by(MY_PLAYER);
  MY_PLAYER->attacked_by(target_obj);
  target_obj->hit_player(target_hp);

  return 1;
}

