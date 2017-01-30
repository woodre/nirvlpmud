inherit "/room/room";
reset(arg) {
  if(arg) return;
  short_desc = "Part of the SouthEast Loop";
  long_desc = "This is part of the southeast loop.\n";
  dest_dir = ({
           "/players/grimm/closed/mall/truck/rh3", "north",
           "/players/grimm/closed/mall/truck/rh1", "south",
           });
}
