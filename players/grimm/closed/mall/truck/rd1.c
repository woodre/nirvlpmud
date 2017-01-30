inherit "/room/room";
reset(arg) {
  if(arg) return;
  short_desc = "Beginning of SouthWest Loop";
  long_desc = "This is the beginning of the southwest loop.\n";
  dest_dir = ({
           "/players/grimm/closed/mall/truck/rd2", "north",
           "/players/grimm/closed/mall/truck/rc1", "west",
           });
}
