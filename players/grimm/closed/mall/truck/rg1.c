inherit "/room/room";
reset(arg) {
  if(arg) return;
  short_desc = "Part of SouthEast Loop";
  long_desc = "This is part of the southeast loop.\n";
  dest_dir = ({
           "/players/grimm/closed/mall/truck/rh1", "east",
           "/players/grimm/closed/mall/truck/rf1", "west",
           });
}
