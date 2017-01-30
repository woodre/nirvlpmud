inherit "/obj/treasure";
reset(arg) {
  if(arg) return;
  set_weight(1000000);
  set_short("A VERY large tree");
  set_long("This is a VERY large tree.  You notice small steps imbedded in\n"+
           "the tree's side leading up.  You may be able to \"climb tree\"\n"+
           "to see what is at the top.\n");
  set_value(0);
  set_alias("tree");
}

id(str) {
  return str=="tree" || str=="large tree"; }

init() {
  add_action("climb","climb");
}

climb(str) {
  if(!str) return;
  if(str!="tree") {
    write("What do you want to climb?\n");
    return 1;
  }
  this_player()->move_player("up the tree#/players/grimm/closed/mall/entrance");
  return 1;
}
