/*
 * Help Badge (hb)
 * Doppleganger help command
 */

status main(string str) {
  string menu;

  switch(str) {
  case "3":
    menu = read_file("/players/guilds/dopplegangers/docs/help3");
    break;
  case "2":
    menu = read_file("/players/guilds/dopplegangers/docs/help2");
    break;
  default:
    menu = read_file("/players/guilds/dopplegangers/docs/help1");
    break;
  }
  write(menu);
  return 1;
}
