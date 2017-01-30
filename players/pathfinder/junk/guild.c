id(str) { return str == "trial"; }
short() { return "trial"; }
long() { write("A trial object.\n");
  }
init() {
  add_action("test_this","test");
  }

test_this(str) {
 object tp;
 tp=this_player();
 tp->set_guild_name("monk");
 return 1;
}
