inherit "/room/room";
reset(arg) {
  if(arg) return;
  short_desc = "Main Loop";
  long_desc = "This is part of the main loop of the maze.\n"+
    "The walls are blackened with the signs of many battles.\n";
  dest_dir = ({
           "/players/grimm/closed/mall/truck/rc4", "north",
           "/players/grimm/closed/mall/truck/rc2", "south",
           "/players/grimm/closed/mall/truck/rb3", "west",
           });
}
