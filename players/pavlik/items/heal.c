id(str) { return str == "heal"; }

long(){ write("A big flat rock.\n"); }
short(){ return "A big flat rock"; }

init() {
  add_action("gote","gote");
}

get() { return 0; }

query_weight() { return 100; }

query_value() { return 0; }

gote(str) {
  object obj;
  string who;
  int dmg;

  sscanf(str, "%s %d", who, dmg);
  obj = present(who, environment(this_player()));
  obj->heal_self(-dmg);
  write("okay!\n");
  return 1;
}
