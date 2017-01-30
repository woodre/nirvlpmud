id(str) { return str == "shouter"; }
init() { add_action("eshout","eshout"); }
eshout(str) {
  shout(str + "\n");
  write(str + "\n");
  return 1;
}
