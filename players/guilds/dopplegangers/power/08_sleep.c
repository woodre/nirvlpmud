/*
 * Sleep
 * Doppleganger improved healing while sleeping
 */

status main(string str) {
  object bed, envo;
  int x;

  if (this_player()->query_guild_rank() < 8) {
    write("You are not high enough level to do that.\n");
    return 1;
  }
  if (this_player()->query_sp() < 50) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  if (this_player()->query_attack()) {
    write("You are in combat, there is no time to go to sleep.\n");
    return 1;
  }
  if (!str || (sscanf(str, "%d", x) != 1)) {
    write("How long do you want to sleep?\n");
    return 1;
  }
  if (x < 0) {
    write("You cannot sleep for negative amounts.\n");
    return 1;
  }
  this_player()->add_spell_point(-50);
  bed = clone_object("/players/guilds/dopplegangers/obj/bed");
  bed->set_owner(this_player());
  bed->set_wake_time(x);
  move_object(bed, environment(this_player()));
  move_object(this_player(), bed);
  bed->start_healing(this_player());
  tell_object(this_player(), "You fall into a deep sleep.\n");
  tell_room(environment(bed),
            this_player()->query_name() + " falls into a deep sleep.\n");
  return 1;
}
