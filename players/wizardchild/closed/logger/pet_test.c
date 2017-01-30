short() { return "A pet tester"; }
long() { 
  write("It allows you to control a guild pet. \n");
  write("set_rank <rnk>  set_type <str> set_owner <me>\n");
  return 1;
}
id(str) { return str == "tester" || str == "logger pack"; }
get() { return 1; }
drop() { destruct(this_object()); }
init() {
  add_action("set_owner", "set_owner");
  add_action("set_rank", "set_rank");
  add_action("set_type", "set_type");
}
set_owner(str) {
  present("pet", environment(this_player()))->set_owner(str);
  return 1;
}
set_rank(str) {
  present("pet", environment(this_player()))->set_rank(str);
  return 1;
}
set_type(str) {
  present("pet", environment(this_player()))->set_type(str);
  return 1;
}
