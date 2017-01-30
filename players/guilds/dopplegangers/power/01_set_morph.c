/*
 * set_morph
 * Change what morph the doppleganger will morph into
 */

status main(string str) {
  object badge;

  badge = present("V-GUILD", this_player());
  if (!str) {
    write("Which morph would you like to have set?\n");
    write("Your choices are:\n");
    write("Bat, Rat");
    if (this_player()->query_guild_rank() > 1)
      write(", Orc, Stalker");
    if (this_player()->query_guild_rank() > 2)
      write(", Wraith, Ghoul\n");
    if (this_player()->query_guild_rank() > 3)
      write("Werewolf, Werebear");
    if (this_player()->query_guild_rank() > 4)
      write(", Gargoyle, Shadow");
    if (this_player()->query_guild_rank() > 20)
      write(", Siren, Swirl");
    write("\n");
    return 1;
  }
  switch(str) {
  case "bat":
  case "rat":
    badge->set_morph(str);
    break;
  case "orc":
  case "stalker":
    if (this_player()->query_guild_rank() > 1)
      badge->set_morph(str);
    else
      return 0;
    break;
  case "wraith":
  case "ghoul":
    if (this_player()->query_guild_rank() > 2)
      badge->set_morph(str);
    else
      return 0;
    break;
  case "werewolf":
  case "werebear":
    if (this_player()->query_guild_rank() > 3)
      badge->set_morph(str);
    else
      return 0;
    break;
  case "gargoyle":
  case "shadow":
    if (this_player()->query_guild_rank() > 4)
      badge->set_morph(str);
    else
      return 0;
    break;
  case "siren":
  case "swirl":
    if (this_player()->query_guild_rank() > 20)
      badge->set_morph(str);
    else
      return 0;
    break;
  default: return 0;
  }
  write("Morph set to " + capitalize((string)badge->query_morph()) + ".\n");
  return 1;
}
