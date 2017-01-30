short() { return "A wormhole [no exits]"; }
long() {
  write("You are inside a wormhole. Type 'ditch' to escape into the polymorph\n"+
  "guild room.\n");
}


init() {
  add_action("ditch","ditch");
}

ditch() {
  this_player()->move_player("out#players/mizan/etheriel/ROOMS/linna");
  return 1;
}

query_light() { return 1; }
reset() {
set_light(1);
move_object(clone_object("/players/mizan/closed/wand"), this_object());
}
