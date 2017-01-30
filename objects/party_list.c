inherit "inherit/treasure";

void reset(status arg) {
  if (arg) return;
  set_sell_destruct(1);
  set_name("list");
  set_short("The list of best parties");
  set_long("Written here is the list of the best parties on Nirvana.\n" +
           "Perhaps you could read it?\n");
  set_weight(1);
  set_value(10);
}

void init() {
  ::init();
  add_action("read_me", "read");
}

status read_me(string str) {
  object obj;

  if (present(str, this_player())) {
    if (str == "list") {
      obj = clone_object("obj/more");
      move_object(obj, environment());
      obj->move("/open/party/party_best");
      return 1;
    }
  }
  return 0;
}

