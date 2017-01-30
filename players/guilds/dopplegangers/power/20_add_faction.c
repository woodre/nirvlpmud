/*
 * Doppleganger command for faction adding/removing
 * Rumplemintz
 */

int main(string str) {
  object person, badge;
  string faction, target;

  if (!str || sscanf(str, "%s %s", target, faction) != 2) {
    write("Syntax: " + query_verb() + " <person> <faction>\n");
    return 1;
  }
  person = find_player(target);
  if (!person) {
    write("That person is not on right now.\n");
    return 1;
  }

  badge = present("V-GUILD", person);

  if (!badge) {
    write(person->query_name() + " does not have a Doppleganger badge!\n");
    return 1;
  }

  if (query_verb() == "add_faction") {
    if (badge->query_faction(faction)) {
      write(person->query_name() + " is already a member of the " +
            capitalize(faction) + " faction.\n");
      return 1;
    }
    badge->set_faction(faction);
    badge->init();
    badge->save_me(1);
    command("renew", person);
    write(person->query_name() + " is now a member of the " +
          capitalize(faction) + " faction.\n");
    return 1;
  } else
  if (query_verb() == "remove_faction") {
    if (!badge->query_faction(faction)) {
      write(person->query_name() + " is not a member of the " +
            capitalize(faction) + " faction.\n");
      return 1;
    }
    badge->remove_faction(faction);
    write(person->query_name() + " has been removed from the " +
          capitalize(faction) + " faction.\n");
    return 1;
  } else {
  write("Listing current factions of " + person->query_name() + ".\n");
  write("Barbarian: " + (badge->query_faction("barbarian") ? "Yes" : "No") +
        "\n");
  write("Mystic:    " + (badge->query_faction("mystic") ? "Yes" : "No") +
        "\n");
  return 1;
  }
}
