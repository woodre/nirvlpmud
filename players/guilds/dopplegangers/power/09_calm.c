/*
 * Calm
 * Doppleganger spell to stop fighting in room
 */

status main(string str) {
  object att, *ob;
  int h, s;

  if (str) return 0;
  if (this_player()->query_guild_rank() < 9) {
    write("You are not high enough level to do that.\n");
    return 1;
  }
  if (this_player()->query_sp() < 50) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }

  s = sizeof(ob = all_inventory(environment(this_player())));
  this_player()->add_spell_point(-50);

  while(h < s) {
    if (att = (object)ob[h]->query_attack()) {
      ob[h]->stop_fight();
      att->stop_fight();
    }
    h ++;
  }
  write("You raise your hands in a magical gesture and stop all fighting.\n");
  say(this_player()->query_name() + " raises " +
      this_player()->query_possessive() + " hands in a magical gesture " +
      "and stops all fighting.\n");
  return 1;
}
