inherit "/room/room";
reset(arg) {
  if(arg) return;
  short_desc = "Top of NorthEast Loop";
  long_desc = "This is the top of the northeast loop.\n";
  dest_dir = ({
           "/players/grimm/closed/mall/truck/rh1", "north",
           "/players/grimm/closed/mall/truck/rh6", "south",
           "/players/grimm/closed/mall/truck/rb7", "east",
           "/players/grimm/closed/mall/truck/rg7", "west",
           });
}
