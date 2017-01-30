inherit "/room/room";
reset(arg) {
  if(arg) return;
  short_desc = "Beginning of the SouthEast Loop";
  long_desc = "This is the beginning of the southeast loop.\n";
  dest_dir = ({
           "/players/grimm/closed/mall/truck/rh2", "south",
           "/players/grimm/closed/mall/truck/rg3", "west",
           });
}
