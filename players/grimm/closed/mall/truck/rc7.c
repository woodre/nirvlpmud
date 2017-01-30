inherit "/room/room";
reset(arg) {
  if(arg) return;
  short_desc = "NorthWest Loop";
  long_desc = "This is part of the northwest loop.\n";
  dest_dir = ({
           "/players/grimm/closed/mall/truck/rd7", "east",
           "/players/grimm/closed/mall/truck/rb7", "west",
           });
}
