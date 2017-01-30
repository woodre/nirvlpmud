inherit "room/room";
reset(arg) {
   if(!present("statue")) {
      move_object(clone_object("players/sandman/OBJ/war_statue"), this_object());
   }
   if(!arg) {
      set_light(1);
      short_desc=("Tower Entrance [up,out]");
      long_desc=
      "An exquisite entry foyer to this magnificent tower. Whoever lives\n" +
      "here is obviously a mighty being.\n";
      dest_dir=
      ({
        "players/sandman/ASGARD/BALDAR/gym", "up",
        "players/sandman/ASGARD/sstreet2", "out"
      });
   }
}
