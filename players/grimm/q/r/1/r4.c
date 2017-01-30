inherit "/room/room";

reset(arg) {
  if(arg) return;
  short_desc="Reese's Mainstreet";
  long_desc="You are on Reese's Mainstreet.\nThe path basically heads "+
            "north and south, but you can see\na small alley heading off to "+
            "the east.  The west part of the\nis 'guarded' by a high hedge.\n";
  items=({
     "alley",
     "The alley heads back into darkness.  The stench from back there is "+
     "almost enough\nto knock you over",
     "hedge",
     "The hedge is approximately 20 foot tall and blocks any exit to the west",
     "hedges",
     "The hedges are approximately 20 feet tall and block any exit to the "+
     "west",
    });
  dest_dir=({
    "/players/grimm/q/r/1/r5", "east",
    "/players/grimm/q/r/entr",   "north",
    "/players/grimm/q/r/1/r11", "south",
    });
}
