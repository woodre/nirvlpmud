inherit "/room/room";
reset(arg) {
  if(arg) return;
  short_desc = "Loop SouthWest";
  long_desc = "This is the end of the southwest loop.\n";
  dest_dir = ({
           "/players/grimm/closed/mall/truck/rb2", "north",
           "/players/grimm/closed/mall/truck/rb7", "south",
           "/players/grimm/closed/mall/truck/rc1", "east",
           "/players/grimm/closed/mall/truck/rh1", "west",
           });
}
