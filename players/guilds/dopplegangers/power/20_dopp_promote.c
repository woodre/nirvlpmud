/*
 * dopp_promote dopp_demote
 * Promote/Demote a player in the guild
 * Rumplemintz
 */

#include <ansi.h>

int main(string str) {
  object ob, badge;
  string reason, name;

  if ((int)this_player()->query_guild_rank() < 20) {
    write("You are not a guild commander.\n");
    return 1;
  }
  if (!str || sscanf(str, "%s %s", name, reason) != 2)  {
    write("Syntax: " + query_verb() + " <who> <reason>\n");
    return 1;
  }
  ob = find_living(name);
  if (!ob || ob->query_invis() > this_player()->query_level()) {
    write("That person is not playing right now.\n");
    return 1;
  }
  if ((string)ob->query_guild_name() != "doppleganger") {
    write("That person is not a Doppleganger!\n");
    return 1;
  }
  badge = present("V-GUILD", ob);

  if (query_verb() == "dopp_promote") {
    if ((int)ob->query_guild_rank() < 15) {
      ob->set_guild_rank( (int)ob->query_guid_rank() + 1);
      "/bin/channel_daemon.c"->channel_message("dopplegangers",
                    ob->query_name() + " has been promoted to level " +
                    ob->query_guild_rank() + " by " +
                    this_player()->query_name() + ".\n",
                    HIR + "[Dopples] " + NORM + "Grimm's Assistant: ");
      write_file("/players/guilds/dopplegangers/log/promote",
                 capitalize((string)this_player()->query_real_name()) +
                 " promoted " +
                 capitalize((string)ob->query_real_name()) +
                 " to guild level " + ob->query_guild_rank() + "\n" +
                 "Reason: " + reason + "\n" +
                 "The time is: " + ctime(time()) + ".\n" +
                 "------------------------------------------------------\n");
      badge->save_me(1);
      return 1;
    } else {
      write(ob->query_name() + " cannot be promoted any higher.\n");
      return 1;
    }
  } else if (query_verb() == "dopp_demote") {
    if ((int)ob->query_guild_rank() > 1) {
      ob->set_guild_rank( (int)ob->query_guild_rank() - 1);
      "/bin/channel_daemon.c"->channel_message("dopplegangers",
                  ob->query_name() + " has been demoted to level " +
                  ob->query_guild_rank() + " by " +
                  this_player()->query_name() + ".\n",
                  HIR + "[Dopples] " + NORM + "Grimm's Assistant: ");
      write_file("/players/guilds/dopplegangers/log/demote",
                 capitalize((string)this_player()->query_real_name()) +
                 " demoted " +
                 capitalize((string)ob->query_real_name()) +
                 " to guild level " + ob->query_guild_rank() + "\n" +
                 "Reason: " + reason + "\n" +
                 "The time is: " + ctime(time()) + ".\n" +
                 "------------------------------------------------------\n");
      badge->save_me(1);
      return 1;
    } else {
      write(ob->query_name() + " cannot be demoted any further.\n");
      return 1;
    }
  } else
    return 0;
}

