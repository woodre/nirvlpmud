/*
 * Shadizar
 * Doppleganger damage spell - 10sp, 8 + random(6) damage
 */

status main(string str) {
  object target;


  if (this_player()->query_guild_rank() < 10) {
    write("You are not high enough level to do that.\n");
    return 1;
  }
  if (this_player()->query_sp() < 10) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  if (!str && !this_player()->query_attack()) {
    write("Cast Shadizar on what?\n");
    return 1;
  }
  if (this_player()->query_attack())
    target = (object)this_player()->query_attack();
  else
    target = present(str, environment(this_player()));
  if (!target) {
    write("Cast Shadizar on what?\n");
    return 1;
  }
  if (!this_player()->query_attack()) this_player()->attack_object(target);
  if (target)
    target->hit_player( (8 + random(6)) );
  else
    return 0;
  this_player()->add_spell_point(-10);
  write("You speak some cryptic words and " + target->query_name() +
        " is engulfed in blue flames.\n");
  say(this_player()->query_name() + " speaks some cryptic words and " +
      target->query_name() + " is engulfed in blue flames.\n");
  return 1;
}
