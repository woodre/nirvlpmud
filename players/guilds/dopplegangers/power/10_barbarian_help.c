/*
 * Barbarian Help (bh)
 * Doppleganger help command
 */

status main(string str) {
  string menu;

  menu = read_file("/players/guilds/dopplegangers/docs/bhelp");
  write(menu);
  return 1;
}
