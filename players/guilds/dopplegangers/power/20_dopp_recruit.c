/*
 * dopp_recruit
 * Recruit a player into the guild
 * Rumplemintz
 */

int main(string str) {
  object ob, badge;

  if ((int)this_player()->query_guild_rank() < 20) {
    write("You are not a guild commander.\n");
    return 1;
  }
  if (!str) {
    write("Who do you want to recruit into the guild?\n");
    return 1;
  }
  ob = find_living(str);
  if (!ob || ob->query_invis() > this_player()->query_level()) {
    write("That person is not playing right now.\n");
    return 1;
  }
  if ((int)ob->query_level() < 3) {
    write("A player must be at least level 3 to join the guild.\n");
    return 1;
  }
  if (ob->query_guild_name()) {
    write("That person is a member of another guild.\n");
    return 1;
  }
  if (present("V-GUILD", ob) ||
      (string)ob->query_guild_name() == "doppleganger" ||
      restore_object("players/guilds/dopplegangers/member/" +
                     (string)ob->query_real_name())) {
    write("That person is already a member.\n");
    return 1;
  }
  write("You have just recruited " + ob->query_name() + " into the guild.\n");
  "/bin/channel_daemon.c"->channel_message("dopplegangers",
               this_player()->query_name() + " just recruited " +
               ob->query_name() + " into the guild!!!\n",
               HIR + "[Dopples] " + NORM + "Grimm's Assistant: ");
  badge = clone_object("/players/guilds/dopplegangers/guildob");
  move_object(badge, ob);
  write_file("/players/guilds/dopplegangers/log/join",
             capitalize((string)this_player()->query_real_name()) +
             " just recruited " +
             capitalize((string)ob->query_real_name()) +
             " into the guild.\n" +
             "The time is: " + ctime(time()) + ".\n" +
             "-----------------------------------------------------------\n");
  ob->set_guild_exp(1);
  ob->set_guild_name("doppleganger");
  ob->set_guild_rank(1);
  ob->set_guild_file("/players/guilds/dopplegangers/guildob.c");
  badge->reset();
  badge->set_morph("bat");
  badge->set_fang_hit(5);
  badge->save_me(1);
  return 1;
}

