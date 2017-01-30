/*
 * Shift
 * Doppleganger spell to temporarily add 4 AC
 * Uses the badge and RegisterArmor instead of old (and no longer working)
 *     add_ac
 */

status main(string str) {
  object badge;

  if (str) return 1;
  if (this_player()->query_guild_rank() < 8) {
    write("You are not high enough level to do that.\n");
    return 1;
  }
  if (this_player()->query_sp() < 25) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  badge = present("V-GUILD", this_player());
  if (badge->query_shift_flag()) {
    write("You are already in a shifted state.\n");
    return 1;
  }
  this_player()->add_spell_point(-25);
  environment(badge)->RegisterArmor(badge, ({"physical", 4, 0, 0}));
  badge->toggle_shift_flag();
  write("You begin to distort yourself, making it harder to be hit.\n");
  say("Your vision of " + this_player()->query_name() +
      " blurs, as " + this_player()->query_pronoun() +
      " distorts " + this_player()->query_possessive() + " figure.\n");
  call_out("stop_shift", 90, this_player());
  return 1;
}

int stop_shift(object obj) {
  object badge;

  badge = present("V-GUILD", obj);
  badge->toggle_shift_flag();
  environment(badge)->RemoveArmor(badge);
  tell_object(obj, "You stop distorting yourself due to exhaustion.\n");
  return 1;
}
