/*
 * Drain corpse for some healing
 */

status main(string str) {
  object corpse;
  object badge;

  badge = present("V-GUILD", this_player());
  if (this_player()->query_guild_rank() < 2) {
    write("You are not a high enough level to do that yet.\n");
    return 1;
  }
  if (this_player()->query_sp() < 2) {
    write("You do not have enough spell points to do that.\n");
    return 1;
  }
  corpse = present("corpse", environment(this_player()));
  if (!corpse)
    corpse = present("corpse", this_player());
  if (!corpse) {
    write("There is no corpse present.\n");
    return 1;
  }
  destruct(corpse);
  if (badge->query_which_drain())
    this_player()->add_spell_point(badge->query_corpse_heal());
  else
    this_player()->add_hit_point(badge->query_corpse_heal());
  this_player()->add_spell_point(-2);
  write("You feel revitalized by the corpse.\n");
  say(this_player()->query_name() + " drains the essence from the corpse.\n");
  return 1;
}
