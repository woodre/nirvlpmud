inherit "/room/room";
reset(arg) {
  if(arg) return;
  short_desc = "NorthWest Loop";
  long_desc = "This is part of the northwest loop.\n";
  dest_dir = ({
           "/players/grimm/closed/mall/truck/rb7", "north",
           "/players/grimm/closed/mall/truck/rb5", "south",
           });
}
