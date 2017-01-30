inherit "room/room";
reset(arg) {
   if(!present("enchantress")) {
      move_object(clone_object("players/sandman/MONSTERS/enchantress"), this_object());
   }
   if(!arg) {
      set_light(1);
      short_desc=("Run down hut");
      long_desc=
      "This is a small ramshackle hut, against one wall is a dusty fire\n" +
      "place with a black culdron boiling on it. Standing in the center of\n" +
      "hut is a strikingly beautiful woman (in an evil way of course), she\n" +
      "has that look like her dinner has just arrived (grin).\n";
      dest_dir=
      ({
        "players/sandman/ASGARD/EVIL/dpath4", "out"
      });
   }
}
