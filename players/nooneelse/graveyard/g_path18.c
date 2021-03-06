/*
  g_path18.c
*/

inherit "room/room";

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
             "players/nooneelse/graveyard/g_path19", "north",
             "players/nooneelse/graveyard/g_path17", "south",
             "players/nooneelse/graveyard/g_path14", "west",
           });
  if (!present("ghoul")) {
    obj=clone_object("players/nooneelse/mon/ghoul");
    move_object(obj, this_object());
    obj=clone_object("players/nooneelse/mon/ghoul");
    move_object(obj, this_object());
    obj=clone_object("players/nooneelse/mon/ghoul");
    move_object(obj, this_object());
  }
}
