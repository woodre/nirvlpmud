inherit "/room/room";
reset(arg) {
  if(arg) return;
  short_desc = "Beginning of NorthEast Loop";
  long_desc = "This is the beginning of the northeast loop.\n";
  dest_dir = ({
           "/players/grimm/closed/mall/truck/rh6", "north",
           "/players/grimm/closed/mall/truck/rg5", "west",
           });
}
