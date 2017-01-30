/*
 * Guild who
 *
 * Rumplemintz
 */

status main(string str) {
  object badge;
  object *people;
  string faction, sex, verb;
  int n, cnt, low, hi;

  cnt = 0;

  switch(query_verb()) {
    case "gw": case "guild_who":
      low = 0; hi = 31;
      break;
    case "gz": case "guild_wiz":
      low = 30; hi = 1001;
      break;
    case "ga": case "guild_all":
      low = 0; hi = 1001;
      break;
  }

  people = users();

  write("-Name-\t\t-F- -Sex- -Lvl- -Location-\n");
  write("-----------------------------------------------------------------\n");

  for (n=0; n<sizeof(people); n++) {
    badge = present("V-GUILD", people[n]);
    if (badge) {
      if (people[n]->query_invis() > this_player()->query_level())
        write("");
      else {
        if (people[n]->query_guild_rank() < hi &&
            people[n]->query_guild_rank() > low) {
          cnt++;
          if (!badge->query_shaddup()) write("*");
          else write(" ");
          write(people[n]->query_name());
          if (strlen((string)people[n]->query_name()) > 6) write("\t");
          else write("\t\t");
          if (badge->query_faction("barbarian") &&
              badge->query_faction("mystic")) faction = "B-M";
          else if (badge->query_faction("barbarian") &&
                   !badge->query_faction("mystic")) faction = "B--";
          else if (badge->query_faction("mystic") &&
                   !badge->query_faction("barbarian")) faction = "--M";
          else faction = "---";
          if ((string)people[n]->query_gender() == "male") sex = "M";
          else if ((string)people[n]->query_gender() == "female") sex = "F";
          else sex = "C";
          write(faction + "   " + sex + "\t  " +
                people[n]->query_guild_rank() + "\t ");
          if (badge->query_morphed())
            write("morphed");
          write(environment(people[n])->short());
          if (people[n]->query_invis() > 0) write("  (invis)");
          if (query_idle(people[n]) > 120)
            write("  (idle:" + (query_idle(people[n])/60) + ")");
          write("\n");
        }
      }
    }
  }
  write("-----------------------------------------------------------------\n");
  write("* denotes a guild member listening to guild chat.\n");
  write("          >>> " + cnt + " people listed. <<< \n\n");
  return 1;
}
