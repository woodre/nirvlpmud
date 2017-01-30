status empty;
short() { return "A nice large bottle of water"; }
long()  {
  write("It looks....."+(empty?"dry":"wet")+"...\n");
  write("Type \"refill\" to refill a water weenie, or \"drink\" to drink it.\n");
  return 1;
}
get() { return 1; }
drop() { return 0; }
query_value() { return 10; }
id(str) { return str == "bottle" || str == "water" || str == "bottle of water"; }
init() {
  if(environment(this_object()) == this_player()) {
    add_action("drink", "drink");
    add_action("refill", "refill");
  } else 
    destruct(this_object());
}
drink(str) {
  if(!id(str)) return 0;
  if(empty) { write("There's no water left.\n"); return 1; }
  write("You drink the water.\n");
  write("As it goes down, you can't stop thinking about how wet it is.\n");
  say(this_player()->query_name()+" drinks some water...Mmm, how wet!\n");
  empty = 1;
  return 1;
}
refill() {
  object ob;
  if(empty) { write("There's no water left.\n"); return 1; }
  ob = present("water weenie", this_player());
  if(!ob) {
    write("You don't have a water weenie.\n");
    return 1;
  }
  if(ob->query_water() == 6) {
    write("It's still full.\n");
    return 1;
  }
  write("You fill up the water weenie.\n");
  say(this_player()->query_name()+" fills his weenie.\n");
  empty = 1;
  ob->add_water(6);
  return 1;
}
