start() {
  shadow(environment(find_player("plasma")), 1);
  write("start");
  return 1;
}
init() {
 add_action("start","start");
}
get() {return 1;}
exit() { write("BLLLHHH"); }
