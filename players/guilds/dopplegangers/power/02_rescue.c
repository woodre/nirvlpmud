/*
 * Rescue
 * Doppleganger guild hall teleport - usable once every 15 minutes
 */

status main(string str) {
  object badge;

  if (str) return 0;
  badge = present("V-GUILD", this_player());
  if (this_player()->query_guild_rank() < 2) {
    write("You are not high enough level to do that yet.\n");
    return 1;
  }
  if (this_player()->query_sp() < 40) {
    write("You do not have enough spell points to do that.\n");
    return 1;
  }
  if (badge->query_res_time() > time()) {
    write("It has not been 15 minutes since your last rescue.\n");
    return 1;
  }
  if ((string)environment(this_player())->realm() == "NT") {
    write("Magical forces are preventing your rescue from here.\n");
    return 1;
  }
  badge->set_res_time(time() + 300);
  write("You step behind your shadow and arrive in the guild.\n");
  say(this_player()->query_name() + " steps behind " +
      this_player()->query_possessive() + " shadow.\n");
  this_player()->add_spell_point(-40);
  tell_room("/players/guilds/dopplegangers/room/guildhall",
            this_player()->query_name()+" steps in from behind the shadows.\n");
  move_object(this_player(), "players/guilds/dopplegangers/room/guildhall");
  return 1;
}
