/*
 * Faction information sign
 * Grimm
 * Recoded by Rumplemintz
 */

inherit "/obj/treasure";

void reset(status arg) {
  if (arg)
    return;
  set_weight(100000000);
  set_value(0);
  set_short("An Information Sign");
  set_id("sign");
  set_long(
"This sign is to give you general information on the updates to the guild.\n" +
"If you have questions, please feel free to post them on the board here.\n" +
"To get information, you can:\n" +
"    info              Get a broad overview of the new items (start here)\n" +
"    info barbarians   Get a detailed description of the Barbarian faction\n" +
"    info mystics      Get a detailed description of the Mystic faction\n" +
"    info map          Show a map of Grimm's Maze area\n" +
"\n" +
"Again, questions should either be placed here on the board, or to one of\n" +
"the Guild Commander's, as they have had time to review the factions.\n");
}

void init() {
  add_action("faction_info", "info");
}

int faction_info(string str) {
  string doc;

  if (!str)
    doc = read_file("/players/guilds/dopplegangers/docs/dopps");
  else switch (str) {
  case "barbarians":
    doc = read_file("/players/guilds/dopplegangers/docs/barbs");
    break;
  case "mystics":
    doc = read_file("/players/guilds/dopplegangers/docs/mystics");
    break;
  case "map":
    doc = read_file("/players/guilds/dopplegangers/docs/map");
    break;
  case "bh":
    doc = read_file("/players/guilds/dopplegangers/docs/bhelp");
    break;
  case "mh":
    doc = read_file("/players/guilds/dopplegangers/docs/mhelp");
    break;
  default:
    this_object()->long();
    return 1;
    break;
  }
  write(doc);
  return 1;
}

