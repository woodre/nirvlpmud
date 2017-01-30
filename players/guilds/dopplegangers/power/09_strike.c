/*
 * Strike
 * Doppleganger damage spell - 40sp for 40 damage
 */

status main(string str) {
  object target;
  string tname;

  if (this_player()->query_guild_rank() < 9) {
    write("You are not high enough level to do that.\n");
    return 1;
  }
  if (this_player()->query_sp() < 40) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  if (!str && !this_player()->query_attack()) {
    write("Strike who?\n");
    return 1;
  }
  if (this_player()->query_attack())
    target = (object)this_player()->query_attack();
  else
    target = present(str, environment(this_player()));
  if (!target) {
    write("Strike who?\n");
    return 1;
  }
  tname = (string)target->query_name();
  if (!this_player()->query_attack()) this_player()->attack_object(target);
  if (target)
    target->hit_player(40);
  else
    return 0;
  this_player()->add_spell_point(-40);
  write("You strike down " + tname + ".\n");
  say(this_player()->query_name() + " strikes down " + tname +
      " with the power of the ancients.\n");
  return 1;
}

