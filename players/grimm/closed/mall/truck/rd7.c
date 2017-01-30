inherit "/room/room";
reset(arg) {
  if(arg) return;
  short_desc = "Beginning of NorthWest Loop";
  long_desc = "This is the beginning of the northwest loop.\n";
  dest_dir = ({
           "/players/grimm/closed/mall/truck/rd6", "south",
           "/players/grimm/closed/mall/truck/rc7", "west",
           });
}
