init() {
  add_action("cmd_who","whotest");
}
cmd_who() {
  return "/players/illarion/test/_who.c"->cmd_who();
}
