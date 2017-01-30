/*
 parlor.c
*/

inherit "room/room";

string str, str2, where;

init() {
  ::init();

  add_action("look_in_hole", "search");
}


look_in_hole(str) {
  if (!str) return;
  str2=0;
  sscanf(str, "%s %s", where, str2);
  if (str != "hole" && str2 != "hole") return;
  if (present("rat")) {
    write("You don't have time to search while you're fighting with a rat!\n");
    return 1;
  }
  if (!present("slingshot", this_player()) &&
      !present("slingshot", environment(this_player()))) {
    say(this_player()->query_name()+" searches the rat hole and finds something.\n");
    write("As you search the hole you find a small magical device.\n");
    move_object(clone_object("players/nooneelse/obj/slingshot"), this_object());
    return 1;
  }
  else {
    say(this_player()->query_name()+" searches the rat hole and finds nothing.\n");
    write("You search the hole and find nothing.\n");
    return 1;
  }
  return 1;
}

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc = "parlor";
  no_castle_flag=1;
  long_desc =
    "This room was tastefully furnished with overstuffed furniture and\n"
    + "velvet wallpaper.  Now, however, the stuffing has been pulled from\n"
    + "the chairs, and the wallpaper is covered with long scratches.\n"
    + "There is a hole in the wall at floor level.  You can barely see\n"
    + "through the dirty windows.\n";
  items =
    ({
      "wallpaper",
        "It used to be pretty and decorative, but is now old and dingy.",
      "furniture",
        "There are several couches and large chairs around the room.",
      "couch", "It is an overstuffed couch, placed next to the wall.",
      "couches",
        "There are several overstuffed couches placed around the room.",
      "chair", "It is a large, comfortable chair.",
      "chairs", "There are several large chairs placed around the room.",
      "stuffing", "It's just old, matted padding that used to make the "+
                  "furniture comfortable.",
      "scratches", "They look like the claw marks of a dog-sized creature.",
      "hole", "It is about the size of a mid-sized dog.  You won't fit.",
      "window", "It is a glass-paned window, with a layer of dirt on it.",
      "windows", "They are glass-paned windows, with a layer of dirt on them.",
    });
  dest_dir =
    ({
      "players/nooneelse/red/hall", "east",
    });
  if (!present("rat"))
    move_object(clone_object("players/nooneelse/mon/parlor_rat"),
                this_object());
}


id (str) {
  if (str=="hole") {
    look_in_hole("hole");
    return 1;
  }
  return (str=="wallpaper" ||
          str=="furniture" ||
          str=="couches" || str=="couch" ||
          str=="chairs" || str=="chair" ||
          str=="stuffing" ||
          str=="scratches" ||
          str=="hole" ||
          str=="window" || str=="windows");
}
