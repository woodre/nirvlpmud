inherit "/room/room";
reset(arg) {
  if(arg) return;
  short_desc = "Top of NorthWest Loop";
  long_desc = "This is the top of the northwest loop.\n";
  dest_dir = ({
           "/players/grimm/closed/mall/truck/rb1", "north",
           "/players/grimm/closed/mall/truck/rb6", "south",
           "/players/grimm/closed/mall/truck/rc7", "east",
           "/players/grimm/closed/mall/truck/rh7", "west",
           });
}
