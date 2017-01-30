id(str) { return str == "plug"; }
short() { return "A plug, plugged into nowhere in particular"; }
long() {
  write("This is a normal electrical cord, with a plug, plugged into absolutely\n"+
"nowhere. It is warm to the touch with electricity.\n");
}

init() {
  add_action("pull","pull");
  add_action("grasp","grasp");
}

pull(str) {
  if(!str || str != "plug") return 0;
  write("ZZZZZZZZAAAAAAPPPPP!!!!!!\n\n"+
    "Ouch! You get electrocuted and fly out of the area.\n");
    this_player()->move_player("X#players/mizan/etheriel/ROOMS/spuck.c");
  return 1;
}

grasp(str) {
  if(!str || str != "plug") return 0;
    write("You pull the plug, and black out.\n\n"+
    "Awakening... you find yourself elsewhere.\n");
    this_player()->move_player("X#players/mizan/etheriel/ROOMS/hangout");
    return 1;
}
