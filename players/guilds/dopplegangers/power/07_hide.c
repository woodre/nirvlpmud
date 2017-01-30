/*
 * Hide
 * Teleports a Doppleganger to the guild hideout
 */

status main(string str) {
  object badge;

  if (this_player()->query_guild_rank() < 7) {
    write("You are not high enough level to do that yet.\n");
    return 1;
  }
  if (this_player()->query_sp() < 40) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  badge = present("V-GUILD", this_player());
  if ((string)environment(this_player())->realm() == "NT") {
    write("Some strange magic is preventing you from hiding.\n");
    return 1;
  }
  badge->set_hiding_return(environment(this_player()));
  write("You run for cover and arrive in the Doppleganger hiding place.\n");
  say(this_player()->query_name() + " ducks behind " +
      this_player()->query_possessive() + " shadow, running for cover.\n");
  move_object(this_player(), "/players/grimm/closed/obj/badge_stuff/hide");
  this_player()->add_spell_point(-40);
  return 1;
}
