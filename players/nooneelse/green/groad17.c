/*
 groad17.c - evil side of green road
*/

inherit "room/room";

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc=("a gloomy path");
  no_castle_flag=1;
  long_desc="You are standing on a path in a gloomy forest.  "+
            "You sense evil everywhere.\n";
  items =
    ({
      "forest", "It is a dense forest.  The trees are too close together for\n"+
                "you to go anywhere except on the path.",
      "path", "It is a narrow, clear path.",
      "trees", 
        "The trees are twisted and diseased.  There are many thornbushes.",
      "tree", "The tree is twisted and diseased.  There are many thornbushes.",
      "thornbush", "The bush is thick and has long, dangerous thorns.",
      "thornbushes", "The bushes are thick and have long, dangerous thorns.",
      "bushes", "The bushes are thick and have long, dangerous thorns.",
      "bush", "The bush is thick and has long, dangerous thorns.",
      "thorns", "The thorns are long and sharp.",
      "thorn", "The thorn is long and sharp.",
    });
  dest_dir=
    ({
      "players/nooneelse/green/groad18", "south",
      "players/nooneelse/green/groad16", "north",
    });
  return;
}
