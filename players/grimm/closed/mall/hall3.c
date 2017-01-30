inherit "/room/room";
reset(arg) {
  if(!present("fountain",this_object())) {
    move_object(clone_object("/players/grimm/q/o/fountain"),this_object());
  }
  if(arg) return;
  short_desc="Mall Hallway";
  long_desc="You are standing in the center of the mall.\n"+
"To the east you can see Zelda's Inn.  In there you can get food for healing\n"+
"and a beer to wash it down.  To the west you can see Ziggy's Arcade.\n"+
"Although his arcade is open 24 hours a day, it is currently closed for\n"+
"renovations (he's trying to get his 50th Street Fighter II game installed).\n"+
"In the center of the room you can see a very large fountain with a few\n"+
"goldfish in the bottom.\n";
  set_light(1);
  dest_dir=({
             "/players/grimm/closed/mall/arcade","west",
             "/players/grimm/closed/mall/inn","east",
             "/players/grimm/closed/mall/hall4","north",
             "/players/grimm/closed/mall/hall2","south",
           });
}

init() {
  ::init();
  add_action("west","west");
}

west() {
  write("Sorry, but Ziggy's arcade is currently closed for renovation.\n");
  return 1;
}
