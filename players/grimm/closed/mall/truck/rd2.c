inherit "/room/room";
reset(arg) {
  if(arg) return;
  short_desc = "Main Loop";
  long_desc = "This is part of the main loop of the maze.\n"+
    "The walls are blackened with the signs of many battles.\n";
  dest_dir = ({
           "/players/grimm/closed/mall/truck/rd1", "south",
           "/players/grimm/closed/mall/truck/re2", "east",
           "/players/grimm/closed/mall/truck/rc2", "west",
           });
}
