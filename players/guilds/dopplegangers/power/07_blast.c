/*
 * Blast
 * Doppleganger damage spell - 15sp 15damage
 */

status main(string str) {
  object target;
  string target_name;

  if (this_player()->query_guild_rank() < 7) {
    write("You are not high enough level to do that.\n");
    return 1;
  }
  if (this_player()->query_sp() < 15) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  if (!str && !this_player()->query_attack()) {
    write("Blast what?\n");
    return 1;
  }
  if (this_player()->query_attack())
    target = (object)this_player()->query_attack();
  else
    target = present(str, environment(this_player()));
  if (!target) {
    write("Blast what?\n");
    return 1;
  }
  target_name = (string)target->query_name();

  if (!this_player()->query_attack()) this_player()->attack_object(target);
  target->hit_player(15);
  this_player()->add_spell_point(-15);
  write("You blast " + target_name + ".\n");
  say(this_player()->query_name() + " blasts " + target_name + ".\n");
  return 1;
}
