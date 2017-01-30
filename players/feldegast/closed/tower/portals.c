inherit "room/room";
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="A marble staircase";
  long_desc=
"You are on a huge marble staircase running up the center of the\n"+
"Crystal Tower.  The staircase stops here at a landing leading up\n"+
"to a strong oak door.\n";
  items=({
  });
  dest_dir=({
    "/players/feldegast/workroom","north",
    "/players/feldegast/closed/tower/silence","south",
    "/players/feldegast/closed/tower/tower2","down"
  });
}
init() {
  ::init();
  add_action("list","list");
  add_action("green","green");
  add_action("post","post");
  add_action("mist","mist");
  add_action("black","black");
  add_action("nexus","nexus");
  add_action("warp","warp");
  add_action("plains","plains");
  add_action("east","east");
  add_action("statue","statue");
  add_action("wastes","wastes");
  add_action("bigelow","bigelow");
  add_action("ryllian","ryllian");

}
green() {
  this_player()->move_player("in a flash of light#room/vill_green");
}
