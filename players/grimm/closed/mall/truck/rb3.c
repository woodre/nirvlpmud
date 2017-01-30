inherit "/room/room";
reset(arg) {
  if(arg) return;
  short_desc = "Beginning of SouthWest Loop";
  long_desc = "This is beginning of the southwest loop.\n";
  dest_dir = ({
           "/players/grimm/closed/mall/truck/rb2", "south",
           "/players/grimm/closed/mall/truck/rc3", "east",
           });
}
