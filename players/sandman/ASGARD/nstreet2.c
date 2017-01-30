inherit "room/room";
reset(arg) {
   if(!present("statue")) {
      move_object(clone_object("players/sandman/OBJ/war_statue"), this_object());
   }
   if(!arg) {
      set_light(1);
      short_desc = "Dead End Street";
      long_desc=
      "The wide street ends here in a dead end. In the center of the street\n"
+     "stands a stone statue of a viking warrior.\n";
      dest_dir=
      ({
        "players/sandman/ASGARD/nstreet1", "south"
      });
   }
}
