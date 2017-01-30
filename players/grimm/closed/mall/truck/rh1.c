inherit "/room/room";
reset(arg) {
  if(arg) return;
  short_desc = "End of SouthEast Loop";
  long_desc = "This is the end of the southeast loop.\n";
  dest_dir = ({
           "/players/grimm/closed/mall/truck/rh2", "north",
           "/players/grimm/closed/mall/truck/rh7", "south",
           "/players/grimm/closed/mall/truck/rb1", "east",
           "/players/grimm/closed/mall/truck/rg1", "west",
           });
}
