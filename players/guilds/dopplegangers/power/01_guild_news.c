/*
 * Doppleganger guild news
 */

status main(string str) {
  if (str) return 0;
  write(read_file("/players/guilds/dopplegangers/docs/guild_news"));
  return 1;
}
