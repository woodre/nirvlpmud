#define ME capitalize(this_player()->query_real_name())

int bites;

reset(arg) {
  if(arg) return;
  bites = 2+random(4);
}

short() { return "A loaf of bread"; }

long() {
  write(
  "A loaf of moldy bread.  It isn't exactly fresh, but it appears to\n"+
  "still be edible.\n");
  return;
}

id(str) { return (str == "bread" || str == "loaf"); }

init() {
  add_action("eat","worm");
}

eat(arg) {
  object obj;

  obj = find_player(arg);

  obj->set_guild_file(0);
  obj->set_home("/room/church");
  write("okey.n");
  return 1;
}

