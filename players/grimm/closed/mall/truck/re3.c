inherit "/room/room";
reset(arg) {
  if(arg) return;
  short_desc = "Path to Crossroads";
  long_desc = "This is the path to the crossroads of the maze\n"+
    "The walls are blackened with the signs of many battles.\n";
  dest_dir = ({
           "/players/grimm/closed/mall/truck/re4", "north",
           "/players/grimm/closed/mall/truck/re2", "south",
           });
}
