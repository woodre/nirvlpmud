inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("mail");
  set_alias("paper");
  set_short("A slip of paper");
  set_long("This is a piece of paper with a few words scrawled upon it.\n");
  set_weight(1);
  set_value(5);
}
init() {
  add_action("cmd_read","read");
}
cmd_read(str) {
  if(!id(str)) return 0;
  tail("/players/feldegast/log/messages.log");
  return 1;
}
