/*
 * Squeeze
 * Doppleganger damage spell - 20sp for 10 damage
 */

status main(string str) {
  object target;

  if (this_player()->query_guild_rank() < 13) {
    write("You are not high enough level to do that.\n");
    return 1;
  }
  if (this_player()->query_sp() < 20) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  if (!str && !this_player()->query_attack()) {
    write("Squeeze what?\n");
    return 1;
  }
  if (this_player()->query_attack())
    target = (object)this_player()->query_attack();
  else
    target = present(str, environment(this_player()));
  if (!target) {
    write("Squeeze what?\n");
    return 1;
  }
  if (!this_player()->query_attack()) this_player()->attack_object(target);
  if (target)
    target->hit_player(10);
  else
    return 0;
  this_player()->add_spell_point(-20);
  write("You squeeze the life out of " + target->query_name() + ".\n");
  say(this_player()->query_name() + " squeezes the life out of " +
      target->query_name()+ ".\n");
  return 1;
}
