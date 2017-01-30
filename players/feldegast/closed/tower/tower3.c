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
  add_action("north","north");
}
north() {
  if(this_player()->query_real_name()!="feldegast") {
    write("The door will not open for you.\n");
    return 1;
  }
}
