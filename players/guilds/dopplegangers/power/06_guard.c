/*
 * Guard
 * Summon a guard to protect a kill
 */

status main(string str) {
  object guard;

  if (this_player()->query_guild_rank() < 6) {
    write("You are not high enough level for that.\n");
    return 1;
  }
  if (this_player()->query_sp() < 10) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  if (!str || !present(str, environment(this_player()))) {
    write("That is not here.\n");
    return 1;
  }
  guard = clone_object("/players/grimm/closed/obj/badge_stuff/marker");
  guard->set_owner(this_player()->query_real_name());
  guard->set_monster(str);
  move_object(guard, environment(this_player()));
  guard->go();
  write("You drop a marker to guard a " + capitalize(str) + ".\n");
  say(this_player()->query_name() + " drops a marker to guard a " +
      capitalize(str) + ".\n");
  return 1;
}
