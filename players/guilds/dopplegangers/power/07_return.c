/*
 * Return
 * Return from the guild hiding place to the prior room
 */

status main(string str) {
  object badge;

  if (str) return 1;
  if (this_player()->query_guild_rank() < 7) {
    write("You are not high enough level to do that.\n");
    return 1;
  }
  if (!environment(this_player())->query_hiding_place()) {
    write("You are not in the Doppleganger hideout!\n");
    return 1;
  }
  if (this_player()->query_sp() < 40) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  badge = present("V-GUILD", this_player());
  if (!badge->query_hiding_return()) {
    write("Your return room is messed up... sending you to the church.\n");
    say(this_player()->query_name() + " gets kicked to the church.\n");
    move_object(this_player(), "/room/church");
    return 1;
  }
  say(this_player()->query_name() + " disappears.\n");
  move_object(this_player(), (object)badge->query_hiding_return() );
  badge->set_hiding_return(0);
  write("You return from the Doppleganger hideout.\n");
  return 1;
}
