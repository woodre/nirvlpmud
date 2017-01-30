/*
 * new commands
 * Command to list new commands for Dopplegangers
 */

status main(string str) {
  if (str) return 0;
  write(read_file("/players/guilds/dopplegangers/docs/new_commands"));
  return 1;
}
