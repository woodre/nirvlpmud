id(str) { return str == "void"; }

short() { return "A void leading to a quite certain death"; }

long() {
  write("You see something VERY big at the end of this tunnel. Maybe it\n"+
	"would not be a good idea to enter, unless you enjoy taking\n"+
	"hits from the multi-headed monster at the other side.\n");
}

init() {
  add_action("enterme","enter");
}

enterme(str) {
  if(!str || str != "void") return 0;
  write("You drift near the void and are sucked in!\n");
  this_player()->move_player("into the void#players/mizan/etheriel/ROOMS/tempest.c");
  command("kick tiamat", this_player());
  return 1;
}
