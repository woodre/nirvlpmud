inherit "room/room";
reset(arg){
  if(!arg){
  set_light(1);
  short_desc = "Nowhere";
  long_desc = "This is simply a plain room inbetween stairwells...\n"+
              "Who knows what might happen here.\n";
  dest_dir = ({
    "players/rumplemintz/room/dlords/castle/room22", "east",
    "players/rumplemintz/room/dlords/castle/room20", "west",
    });
  items = ({
    "room", "It sucks...",
    });
  }
}
