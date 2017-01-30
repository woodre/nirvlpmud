inherit "/room/room";
reset(arg) {
  if(arg) return;
  short_desc = "Part of NorthEast Loop";
  long_desc = "This is part of the northeast loop.\n";
  dest_dir = ({
           "/players/grimm/closed/mall/truck/rb7", "east",
           "/players/grimm/closed/mall/truck/rf7", "west",
           });
}
