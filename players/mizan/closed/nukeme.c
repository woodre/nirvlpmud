init() {
  add_action("q","q");
}

q() {
  this_player()->set_home("invalid");
  this_player()->set_guild_file("invalid");
  return 1;
}
