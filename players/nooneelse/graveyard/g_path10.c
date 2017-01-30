/*
  g_path10.c
*/

inherit "room/room";

realm() { return "NT"; }

reset(arg) {
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
             "players/nooneelse/graveyard/g_path11", "north",
             "players/nooneelse/graveyard/g_path9", "south",
           });
}
