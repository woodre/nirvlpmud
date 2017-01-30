/*
 * dopp_status
 * Query the doppleganger guild status of a member
 * Rumplemintz
 */

int main(string str) {
  object ob, badge;

  if (!str) {
    write("Who do you want to check the status of?\n");
    return 1;
  }
  if ((int)this_player()->query_guild_rank() < 20) {
    write("You are not a guild commander.\n");
    return 1;
  }

  ob = find_living(str);
  if (!ob ||
      ob->query_invis() > this_player()->query_level()) {
    write("That person is not playing right now.\n");
    return 1;
  }
  if ((string)ob->query_guild_name() != "doppleganger") {
    write("That person is not a Doppleganger.\n");
    return 1;
  }
  badge = present("V-GUILD", ob);

  write("Name:         " + ob->query_name() + "\n");
  write("Guild Exp:    " + ob->query_guild_exp() + "\n");
  write("Guild Level:  " + ob->query_guild_rank() + "\n");
  write("Level:        " + ob->query_level() + "\n");
  if (badge) {
    if (badge->query_faction("barbarian"))
      write("Faction:      Barbarian\n");
    if (badge->query_faction("mystic"))
      write("Faction:      Mystic\n");
  }
  return 1;
}

