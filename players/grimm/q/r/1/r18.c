inherit "/room/room";

reset(arg) {
  if(arg) return;
  short_desc="Reese's Mainstreet";
  long_desc="You are on the Mainstreet of Reese.\nThe path heads north and "+
            "west from here.  To the west you can see\na large fountain.\n";
  items=({
     "hedge",
     "The hedge is approximately 20 foot tall and blocks any exit to the west",
     "hedges",
     "The hedges are approximately 20 feet tall and block any exit to the "+
     "west",
    });
  dest_dir=({
    "/players/grimm/q/r/1/r11", "north",
    "/players/grimm/q/r/1/r17", "west",
    });
}
