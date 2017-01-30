/*
 * Pet
 * Doppleganger summon pet command
 */

status main(string str) {
  object pet, badge;

  badge = present("V-GUILD", this_player());

  if (str) return 0;
  if (this_player()->query_guild_rank() < 6) {
    write("You are not high enough level for that.\n");
    return 1;
  }
  if (this_player()->query_sp() < 100) {
    write("You do not have enough spell points to do that.\n");
    return 1;
  }
  if ((present("pet", environment(this_player())) &&
      present("pet", environment(this_player()))->query_owner() ==
              this_player()->query_real_name()) ||
      badge->query_pet_object()) {
    write("You already have a pet.\n");
    return 1;
  }
  write("You summon a pet.\n");
  say(this_player()->query_name() + " summons a pet to " +
      this_player()->query_possessive() + " side.\n");
  pet = clone_object("/players/guilds/dopplegangers/obj/dopp_pet");
  pet->set_owner(this_player()->query_real_name());
  move_object(pet, environment(this_player()));
  pet->go();
  badge->set_pet_object(pet);
  this_player()->add_spell_point(-100);
  return 1;
}
