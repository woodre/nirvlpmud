inherit "/obj/treasure.c";

void reset(int arg) {
  if(arg) return;
  set_id("wand");
  set_short("Test wand");
  set_long("A test wand");
}
void init() {
  add_action("cmd_pres","pres");
  add_action("cmd_find","find");
  add_action("cmd_find2", "find2");
  add_action("cmd_find3", "find3");
}

cmd_pres(str) {
  present(str,environment(this_player()));
  return 1;
}

cmd_find(str) {
  find_living(str);
  return 1;
}

cmd_find2(str) {
  find_player(str);
  return 1;
}

cmd_find3(str) {
  find_object(str);
  return 1;
}
