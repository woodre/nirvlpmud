short() { return "A condom dispenser"; }
long() {
  write("It looks like you stick money in and pull the lever.\n");
  write("For you, i'll make it simple: type 'buy condom' (200 coins)\n");
  return 1;
}
id(str) { return str == "dispenser" || str == "condom dispenser"; }
get() {
  write("That horney, are we?\n");
  return 0;
}
init() {
  add_action("buy", "buy");
}
buy(str) {
  object ob;
  if(str != "condom") return 0;
  if(this_player()->query_money() < 200) {
    write("You do not have enough money.\n");
    return 1;
  }
  ob = clone_object("/players/wizardchild/misc/condom.c");
  move_object(ob, this_player());
  this_player()->add_money(-200);
  write("You buy a condom.\n");
  say(this_player()->query_name()+" buys a condom.\n");
  return 1;
}
