/*
  g_path20.c
*/

inherit "room/room";

init() {
  ::init();

  add_action("east", "east");
}

east() {
  if (present("adherer") && this_player()->query_level() < 21) {
    tell_room(this_object(),
        "The adherer steps in front of "+this_player()->query_name()+
        ", preventing passage to the east.\n");
    return 1;
  }
  if (this_player()->query_level() >= 21)
    write("<<<Players can't walk past the adherer when it's here>>>\n");
}

realm() { return "NT"; }

reset(arg) {
  object obj;
  if (arg) return 0;

  set_light(1);
  short_desc="Path in a graveyard";
  long_desc="You are on a path in a forbidding graveyard.  There are\n"+
           "several graves and a few crypts on both sides of the path.\n";
  items=({
          "path",
            "It is a weed-covered gravel path that crunches when you walk",
          "graves",
            "There are weeds growing over the crumbling headstones",
          "grave", "There are weeds growing over the crumbling headstone",
          "crypts", "Their granite blocks are covered with a dark moss",
          "crypt", "It's granite blocks are covered with dark moss",
        });
  dest_dir=({
             "players/nooneelse/graveyard/g_path_crypte", "east",
             "players/nooneelse/graveyard/g_path19", "south",
           });
  if (!present("adherer")) {
    obj=clone_object("players/nooneelse/mon/adherer");
    move_object(obj, this_object());
  }
}
