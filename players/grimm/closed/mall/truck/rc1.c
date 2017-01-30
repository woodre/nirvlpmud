inherit "/room/room";
reset(arg) {
  if(arg) return;
  short_desc = "Part of the SouthWest Loop";
  long_desc = "This is part of the southwest loop.\n";
  dest_dir = ({
           "/players/grimm/closed/mall/truck/rd1", "east",
           "/players/grimm/closed/mall/truck/rb1", "west",
           });
}
