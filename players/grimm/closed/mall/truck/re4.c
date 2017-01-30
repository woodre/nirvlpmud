inherit "/room/room";
reset(arg) {
  if(arg) return;
  short_desc = "Crossroads";
  long_desc = "This is what seems to be a crossroads for the maze.\n"+
              "The walls are blackened with the signs of many battles.\n";
  dest_dir = ({
           "/players/grimm/closed/mall/truck/re5", "north",
           "/players/grimm/closed/mall/truck/re3", "south",
           "/players/grimm/closed/mall/truck/rf4", "east",
           "/players/grimm/closed/mall/truck/rd4", "west",
           });
}
