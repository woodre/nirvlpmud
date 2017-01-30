inherit "/room/room";
reset(arg) {
  if(arg) return;
  short_desc = "Starting Room";
  long_desc = "This is the starting room for the race.\n";
  dest_dir = ({
           "/players/grimm/closed/mall/truck/re2", "north",
           });
}
