short() { return "A pet loader"; }
long() {
  write("Usage: setup <type> where type is eagle, beaver, or duck.\n");
  return 1;
}
id(str) { return str == "logger pack" || str == "loader"; }
get() { return 1; }
init() {
  if(this_player()->query_level() < 21) destruct(this_object());
  else {
    add_action("setup", "setup");
  }
}
query_stable_mode() { return 1; }
setup(str) {
  object ob;
  if(str != "eagle" && str != "beaver" && str != "duck") return 0;
  ob = clone_object("/players/wizardchild/closed/logger/pet.c");
  ob->set_owner(this_player()->query_real_name());
  ob->set_type(str);
  move_object(ob, environment(this_player()));
  return 1;
}
