/*
 * Help Badge (hb)
 * Doppleganger help command
 */

status main(string str) {
  string menu;

  if ((int)this_player()->query_guild_rank() < 20) {
    return 0;
  }
  menu = read_file("/players/guilds/dopplegangers/docs/chelp");
  write(menu);
  return 1;
}

