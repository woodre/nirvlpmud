inherit "room/room";
reset(arg) {
   if(!present("fandral")) {
      move_object(clone_object("players/sandman/MONSTERS/fandral"), this_object());
   }
   if(!present("volstagg")) {
         move_object(clone_object("players/sandman/MONSTERS/volstagg"), this_object());
   }
   if(!present("hogun")) {
      move_object(clone_object("players/sandman/MONSTERS/hogun"), this_object());
   }
   if(!arg) {
      set_light(1);
      short_desc=("Entrance to Asgard [e,w]");
      long_desc=
      "A giant rainbow starts/ends here at the begining of a wide stone\n"+
      "paved street. The street leads east and is lined with golden halls\n"+
      "and majestic towers. It seems all the splenors of Asgard awaits.\n";
      dest_dir=
      ({
        "players/sandman/ASGARD/mstreet1", "east",
        "players/sandman/ASGARD/bridge", "west"
      });
   }
}
