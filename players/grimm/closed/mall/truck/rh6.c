inherit "/room/room";
reset(arg) {
  if(arg) return;
  short_desc = "Part of the NorthEast Loop";
  long_desc = "This is part of the northeast loop.\n";
  dest_dir = ({
           "/players/grimm/closed/mall/truck/rh7", "north",
           "/players/grimm/closed/mall/truck/rh5", "south",
           });
}
