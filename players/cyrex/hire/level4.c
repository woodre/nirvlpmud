inherit "room/room";

reset(arg) {
 if(!present("assistant")) {
   move_object(clone_object("players/cyrex/hire/assistant"), this_object());
 }
  if(!arg) {
  set_light(1);
  short_desc = "Level 4";
  long_desc =
   "You are just one up away from the chamber. Everything is quite bright\n"+
   "up here. The air is certainly more breathable up here. The noise is\n"+
   "extremely loud now.\n";
  items = ({"chamber",
            "Looks like this place can benefit you"});
dest_dir = ({
               "players/cyrex/hire/level3", "down"});
  }
}

