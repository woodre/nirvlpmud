/*
 * Terminate
 * Doppleganger damage spell - 30sp for 15 + random(30) damage
 */

status main(string str) {
  object target;
  string tname;

  if (this_player()->query_guild_rank() < 13) {
    write("You are not high enough level to do that.\n");
    return 1;
  }
  if (this_player()->query_sp() < 30) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  if (!str && !this_player()->query_attack()) {
    write("Terminate what?\n");
    return 1;
  }
  if (this_player()->query_attack())
    target = (object)this_player()->query_attack();
  else
    target = present(str, environment(this_player()));
  if (!target) {
    write("Terminate what?\n");
    return 1;
  }
  if (!this_player()->query_attack()) this_player()->attack_object(target);

  tname = (string)target->query_name();
  if (target)
    target->hit_player((15 + random(30)));
  else
    return 0;
  this_player()->add_spell_point(-30);
  write("You cast a termination spell at " + tname + ".\n");
  say(this_player()->query_name() + " casts a termination spell at " +
      tname + ".\n");
  return 1;
}
