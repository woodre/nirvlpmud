/*
  g_path0.c
*/

inherit "room/room";

realm() { return "NT"; }

reset(arg) {
  if (arg) return 0;

  set_light(1);
  short_desc="Entrance to a graveyard";
  long_desc="You are in the entrance to a forbidding graveyard.\n";
  items=({
          "path",
            "It is a weed-covered gravel path that crunches when you walk",
        });
  dest_dir=({
             "players/nooneelse/graveyard/g_path1", "north",
             "players/nooneelse/entryforest/e_forest8", "south",
           });
}
