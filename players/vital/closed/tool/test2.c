
inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("commands");
}

init() {
  add_action("cmd","lsee");
}

cmd(str) {
    ls(str);
}
