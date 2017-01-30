short() { return "A tractor beam"; }
long()  {
  write("A tractor beam, stemming from the front of the Defiant to its target.\n");
  return 1;
}
id(str) { return str == "tractor_beam"; }
get() { return 1; }
init()  {
  if(environment(this_player()) == this_object())
    add_action("cmd_hook"); add_xverb("");
}
cmd_hook(str) {
  if(this_player()->query_level() >= 60) {
    write("You have been removed from the tractor beam. Don't come back.\n");
    this_player()->move_player("X#room/church");
    return 1;
  }
  write("The tractor beam prevents you from moving.\n");
  return 1;
}
