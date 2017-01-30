inherit "/room/room";
reset(arg) {
  if(arg) return;
  short_desc = "Beginning of NorthWest Loop";
  long_desc = "This is the beginning of the northwest loop.\n";
  dest_dir = ({
           "/players/grimm/closed/mall/truck/rb6", "north",
           "/players/grimm/closed/mall/truck/rc5", "east",
           });
}
