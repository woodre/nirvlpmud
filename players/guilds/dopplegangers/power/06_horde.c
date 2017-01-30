/*
 * Horde
 * Doppleganger damage spell - 30sp for 30 damage
 */

status main(string str) {
  object target;
  string tname;

  if (this_player()->query_guild_rank() < 6) {
    write("You are not high enough level to do that.\n");
    return 1;
  }
  if (this_player()->query_sp() < 30) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  if (!str && !this_player()->query_attack()) {
    write("Send a horde on what?\n");
    return 1;
  }
  if (this_player()->query_attack())
    target = (object)this_player()->query_attack();
  else
    target = present(str, environment(this_player()));
  if (!target) {
    write("Send a horde on what?\n");
    return 1;
  }
  if (!this_player()->query_attack()) this_player()->attack_object(target);
  if (target) {
    /* Evaluate name here, in case it gets killed before the messages
       get generated */
    tname = (string)target->query_name();
    target->hit_player(30);
  }    
  else
    return 0;
  this_player()->add_spell_point(-30);
  write("You send a horde of little dopples to beat the pulp out of " +
        tname + ".\n");
  say(this_player()->query_name() + " sends a horde of little Dopplegangers " +
      "against " + tname + ".\n");
  return 1;
}
