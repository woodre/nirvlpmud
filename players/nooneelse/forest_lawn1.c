/*
  forest_lawn1.c
*/

inherit "room/room";

reset(arg) {
  if (arg) return 0;

  set_light(1);
  short_desc="Sylvan glade";
  long_desc="You are in the middle of a peaceful glade.  The grass is\n"+
            "a lush deep green and the trees surrounding it are strong\n"+
            "and tall.  There is a gentle, warm breeze causing the drooping\n"+
            "branches of the weeping willows to sway gently.\n";
  items=({
          "grass",
             "The deep green grass is tall and looks comfortable to sit on",
          "tree",
             "It is a marvelous example of it's kind.  Tall and strong",
          "trees",
             "They are marvelous examples of their kind.  Tall and strong",
        });
  dest_dir=({
             "room/vill_green", "north",
           });
  if (!present("protege stone"))
    move_object(clone_object("/players/nooneelse/gravestone_protege"),
                this_object());
  if (!present("statue"))
    move_object(clone_object("players/sandman/OBJ/cstatue"), this_object());
}
