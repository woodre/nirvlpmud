/*
 * Tonic
 * Doppleganger heal spell - cost 2sp per 1hp healed
 */

status main(string str) {
  int amt;

  if (!str || (sscanf(str, "%d", amt) != 1)) {
    write("How much do you want your tonic to heal?\n");
    return 1;
  }
  if (this_player()->query_guild_rank() < 2) {
    write("You are not high enough level to do that yet.\n");
    return 1;
  }
  if (amt <= 0) {
    write("You must tonic a positive amount.\n");
    return 1;
  }
  if (this_player()->query_spell_point() < (amt*2)) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  write("You create and apply a tonic to your wounds.\n");
  say(this_player()->query_name() + " applies a tonic to " +
      this_player()->query_possessive() + " wounds.\n");
  this_player()->add_hit_point(amt);
  this_player()->add_spell_point(-(amt*2));
  return 1;
}
