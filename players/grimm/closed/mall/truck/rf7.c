inherit "/room/room";
reset(arg) {
  if(arg) return;
  short_desc = "Beginning of NorthEast Loop";
  long_desc = "This is beginning of the northeast loop.\n";
  dest_dir = ({
           "/players/grimm/closed/mall/truck/rf6", "south",
           "/players/grimm/closed/mall/truck/rg7", "east",
           });
}
