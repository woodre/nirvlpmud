inherit "room/room";

reset(arg) {
 if(!present("drunk")) {
   move_object(clone_object("players/cyrex/hire/drunk"), this_object());
 }
  if(!arg) {
  set_light(1);
  short_desc = "Level 2";
  long_desc =
   "You continue up in the ship. Everything seems to be getting a little\n"+
   "more brighter. The air even seems a bit more fresher. There is some\n"+
   "sort of chamber up this way. There seems to be a lot of noise coming\n"+
   "from it. The noise is getting louder.\n";
  items = ({"chamber",
            "It is still pretty far away to tell"});
  dest_dir = ({"players/cyrex/hire/level3", "up",
               "players/cyrex/hire/level1", "down"});
  }
}

