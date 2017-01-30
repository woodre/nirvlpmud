/*
 * dopp_remove
 * Remove a player from the Doppleganger guild
 * Rumplemintz
 */

int main(string str) {
  object ob, badge;
  string reason, name;

  if ((int)this_player()->query_guild_rank() < 20) {
    write("You are not a guild commander.\n");
    return 1;
  }
  if (!str) {
    write("Who do you want to remove from the guild?\n");
    return 1;
  }
  if (sscanf(str, "%s %s", name, reason) != 2) {
    write("Syntax: dopp_remove <who> <reason>\n");
    return 1;
  }
  ob = find_living(name);
  if (!ob ||
      ob->query_invis() > this_player()->query_level()) {
    write("That person is not playing right now.\n");
    return 1;
  }
  if (name == "grimm" || name == "rumplemintz") {
    write(capitalize(name) + " laughs in your face!\n");
    return 1;
  }
  badge = present("V-GUILD", ob);
  if (!badge ||
      (string)ob->query_guild_name() != "doppleganger" ||
      !restore_object("players/guilds/dopplegagners/member/ " +
                      ob->query_real_name())) {
    write("That person is not a member of the guild.\n");
    return 1;
  }
  ob->add_exp( (int)ob->query_exp() - ((int)ob->query_exp()/6));
  destruct(badge);
  ob->set_guild_name(0);
  ob->set_guild_file(0);
  ob->set_guild_rank(0);
  ob->set_guild_exp(0);
  ob->set_guild_level(0);
  tell_object(ob, "You have been removed from the Doppleganger's guild by " +
              this_player()->query_name() + "\n" +
              "For the reason: " + reason + "\n" +
              "If there are any questions about this, please mail any " +
              "current guild wizard.\n");
  "/bin/channel_daemon.c"->remove_channel("dopplegangers", ob);
  "/bin/channel_deamon.c"->remove_channel("dopplegangersB", ob);
  "/bin/channel_daemon.c"->remove_channel("dopplegangersM", ob);
  write_file("/players/guilds/dopplegangers/lob/unjoin",
             capitalize((string)ob->query_real_name()) +
             " was removed from the guild by " +
             capitalize((string)this_player()->query_real_name()) +
             "\nFor the reason: " + reason + "\n" +
             "The time is: " + ctime(time()) + ".\n" +
             "----------------------------------------------------------\n");
  return 1;
}

