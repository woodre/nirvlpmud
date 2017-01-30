inherit "room/room";

reset(arg) {
 if(!present("shades")) {
   move_object(clone_object("players/cyrex/hire/shades"), this_object());
 }
  if(!arg) {
  set_light(1);
  short_desc = "Level 3";
  long_desc =
   "You continue up in the ship. Everything seems to be getting a little\n"+
   "more brighter. The air even seems a bit more fresher. There is some\n"+
   "sort of chamber up this way. There seems to be a lot of noise coming\n"+
   "from it. The noise is getting really loud.\n";
  items = ({"chamber",
            "It is still pretty far away to tell"});
  dest_dir = ({"players/cyrex/hire/level4", "up",
               "players/cyrex/hire/level2", "down"});
  }
}

