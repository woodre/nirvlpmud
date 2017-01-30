/*
 * Scan
 * Doppleganger spell to get percent readout of NPC hp
 */

status main(string str) {
  object target;

  if (this_player()->query_guild_rank() < 5) {
    write("You are not high enough level to do that.\n");
    return 1;
  }
  if (this_player()->query_sp() < 5) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  if (!str) {
    write("What do you want to scan?\n");
    return 1;
  }
  target = present(str, environment(this_player()));
  if (!target) {
    write("That is not here.\n");
    return 1;
  }
  write(target->query_name() + " has " +
        (100 * ((int)target->query_hp()) / ((int)target->query_mhp())) +
        "% of " + target->query_possessive() + " hit points left.\n");
  this_player()->add_spell_point(-5);
  return 1;
}
