inherit "/room/room";
reset(arg) {
  if(arg) return;
  short_desc = "Main Loop";
  long_desc = "This is part of the main loop of the maze.\n"+
    "The walls are blackened with the signs of many battles.\n";
  dest_dir = ({
           "/players/grimm/closed/mall/truck/re3", "north",
           "/players/grimm/closed/mall/truck/start", "south",
           "/players/grimm/closed/mall/truck/rf2", "east",
           "/players/grimm/closed/mall/truck/rd2", "west",
           });
}
