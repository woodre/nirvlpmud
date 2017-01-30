id(str) { return str == "tunnel"; }
short() { return "A one-way tunnel to the vending machine"; }
long() {
  write("This is a dimensional anomaly forged of the same stuff that\n"+
  "makes bathroom tiles stick to the floor. Was it tile adhesive? Or grout?\n"+
  "Does it matter? Not really, except that you can 'enter' this tunnel\n"+
  "or 'dive' into it and it (should) take you where it says... to the\n"+
  "area where the vending machine likes to hang out.\n");
}

init() {
  add_action("enter","enter");
  add_action("dive","dive");
}

dive() {
  write("You dive into the tunnel and emerge somewhere else...\n");
  this_player()->move_player("into the tunnel#players/mizan/etheriel/ROOMS/nuck.c");
  return 1;
}

enter(str) {
  if(!str || str != "tunnel") return 0;
  write("You enter the tunnel and emerge somewhere else...\n");
  this_player()->move_player("into the tunnel#players/mizan/etheriel/ROOMS/nuck.c");
  return 1;
}
