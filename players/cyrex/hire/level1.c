inherit "room/room";

reset(arg) {
 if(!present("technician")) {
   move_object(clone_object("players/cyrex/hire/technician"), this_object());
 }
  if(!arg) {
  set_light(1);
  short_desc = "Level 1";
  long_desc =
   "You are ascending up in the ship. Everything seems to be getting a\n"+
   "little brighter. The air even seems a bit more fresher. There is some\n"+
   "sort of chamber up this way. There seems to be a lot of noise coming\n"+
   "from it.\n";
  items = ({"chamber",
            "It is still pretty far away to tell"});
  dest_dir = ({"players/cyrex/hire/level2", "up",
               "players/cyrex/cargobay", "down"});
  }
}

