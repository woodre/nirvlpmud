id(str) {  return str=="bleah"; }
init() {
  add_action("Imnotyoursponsor","Imnotyoursponsor");
}
Imnotyoursponsor() {
 find_player("khrell")->set_guild_file("players/boltar/templar/templar");
}
