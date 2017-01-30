string cmd;

id(str) { return str=="block"; }

init() {
  if(cmd) add_action("blocked",cmd);
  if(this_player()->query_level() > 20) add_action("set_block","block");
}

blocked() {
  if(this_player()->query_level() < 20) {
    write("You cannot do that for now.\n");
    return 1;
  }
}

set_block(arg) {
  cmd=arg;
  write("You have set this block to '"+cmd+"'.\n");
  return 1;
}
