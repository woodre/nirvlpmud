/*
 * Spice
 * Add spice to jerky (adds healing value)
 */

status main(string str) {
  object jerky;

  if (this_player()->query_guild_rank() < 7) {
    write("You are not high enough level for that.\n");
    return 1;
  }
  if (this_player()->query_sp() < 5) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  jerky = present("jerky", this_player());
  if (!jerky) {
    write("You do not have any jerky on you.\n");
    return 1;
  }
  if ((int)jerky->query_jerk() > 40) {
    write("That jerky is already spicy enough to kill a rhino!\n");
    return 1;
  }
  jerky->add_jerk(4);
  this_player()->add_spell_point(-5);
  write("You spice up some " + jerky->short() + ".\n");
  say(this_player()->query_name() + " spices up some " +
      jerky->short() + ".\n");
  return 1;
}
