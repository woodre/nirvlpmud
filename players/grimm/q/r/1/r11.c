inherit "/room/room";

reset(arg) {
  if(arg) return;
  short_desc="Reese's Mainstreet";
  long_desc="You are on Reese's Mainstreet.\n The path basically heads "+
            "north and south.  The hedges on\neither side of the path mixed "+
            "with the soft chirp of an\noccasional bird make the area quite "+
            "serene.\n";
  items=({
     "hedge",
     "The hedge is approximately 20 foot tall and blocks any exit to the west",
     "hedges",
     "The hedges are approximately 20 feet tall and block any exit to the "+
     "west",
    });
  dest_dir=({
    "/players/grimm/q/r/1/r4", "north",
    "/players/grimm/q/r/1/r18", "south",
    });
}
