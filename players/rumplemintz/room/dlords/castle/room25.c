inherit "room/room";
reset(arg){
  if(!arg){
  set_light(1);
  short_desc = "Nowhere";
  long_desc = "You can sense the presence of something evil lurking to the east.\n"+
               "You begin to doubt that you are strong enough to fulfill your quest.\n"+
               "If you think you can handle the pressure, venture east...\n";
  dest_dir = ({
    "players/rumplemintz/room/dlords/castle/final", "east",
    "players/rumplemintz/room/dlords/castle/room24", "south",
    });
  }
}
