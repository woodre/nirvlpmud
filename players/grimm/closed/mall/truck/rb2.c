inherit "/room/room";
reset(arg) {
  if(arg) return;
  short_desc = "SouthWest Loop";
  long_desc = "This is part of the SouthWest Loop.\n";
  dest_dir = ({
           "/players/grimm/closed/mall/truck/rb3", "north",
           "/players/grimm/closed/mall/truck/rb1", "south",
           });
}
