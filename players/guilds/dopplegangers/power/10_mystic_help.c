/*
 * Mystic Help (mh)
 * Doppleganger help command
 */

status main(string str) {
  string menu;

  menu = read_file("/players/guilds/dopplegangers/docs/mhelp");
  write(menu);
  return 1;
}
