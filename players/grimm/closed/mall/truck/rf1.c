inherit "/room/room";
reset(arg) {
  if(arg) return;
  short_desc = "Beginning of the SouthEast Loop";
  long_desc = "This is the beginning of the southeast loop.\n";
  dest_dir = ({
           "/players/grimm/closed/mall/truck/rf2", "north",
           "/players/grimm/closed/mall/truck/rg1", "east",
           });
}
