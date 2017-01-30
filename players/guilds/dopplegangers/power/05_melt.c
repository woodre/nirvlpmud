/*
 * melt
 * Doppleganger damage spell - 10sp for 10 damage
 */

status main(string str) {
  object target;

  if (this_player()->query_guild_rank() < 5) {
    write("You are not high enough level to do that.\n");
    return 1;
  }
  if (this_player()->query_sp() < 10) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  if (!str && !this_player()->query_attack()) {
    write("Melt who?\n");
    return 1;
  }
  if (this_player()->query_attack())
    target = (object)this_player()->query_attack();
  else
    target = present(str, environment(this_player()));
  if (!target) {
    write("Melt who?\n");
    return 1;
  }
  if (!this_player()->query_attack()) this_player()->attack_object(target);
  if (target)
    target->hit_player(10);
  else
    return 0;
  this_player()->add_spell_point(-10);
  write("You melt " + target->query_name() + "'s brain.\n");
  say(this_player()->query_name() + " melts " + target->query_name() +
      "'s brains.\n");
  return 1;
}
