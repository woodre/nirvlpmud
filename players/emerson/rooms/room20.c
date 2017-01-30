inherit "room/room.c";

reset(arg) {
  if(arg) return;
  ::reset();
  short_desc="Hallway";
  long_desc="Long desc\n";
  dest_dir=({
    "north","players/emerson/rooms/wait",
     "south","players/emerson/rooms/room21"
  });
}

init() {
  ::init();
  add_action("south","south");
}

south() {
  if(!present("ntag", this_player())) {
     write("You are not an employee!\n");
    return 1;
  }
  this_player()->move_player("south#players/emerson/rooms/room21");
  return 1;
}
