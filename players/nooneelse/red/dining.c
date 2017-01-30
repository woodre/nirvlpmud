/*
 dining.c
*/

inherit "room/room";

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc = "dining room";
  no_castle_flag=1;
  long_desc =
    "This is a large dining room.  There is a large oak table running\n"+
    "almost the entire length of the room.  On the table is a fine linen\n"+
    "table cloth and several dozen chairs, place settings and candlesticks.\n";
  items =
    ({
      "table", "A strong, heavy table made of fine oak.",
      "table cloth", "An extremely long, very fine, white linen cloth.",
      "settings", "There are plates, bowls, knifes, forks, spoons and goblets.",
      "setting", "There is a plate, bowl, knife, fork, spoon and goblet.",
      "candlesticks", "Shining brass candlesticks.",
      "candlestick", "A shining brass candlestick.",
      "chairs", "Straight-backed padded oak chairs.",
      "chair", "A straight-backed padded oak chair.",
      "plates", "Fine white china plates.",
      "plate", "A fine white china plat.e",
      "bowls", "Fine white china bowls.",
      "bowl", "A fine white china bowl.",
      "knifes", "Shiny silver butter knifes.",
      "knife", "A shiny silver butter knife.",
      "forks", "Shiny silver forks.",
      "fork", "A shiny silver fork.",
      "spoons", "Shiny silver spoons.",
      "spoon", "A shiny silver spoon.",
      "goblets", "Shiny silver goblets.",
      "goblet", "A shiny silver goblet.",
    });
  dest_dir =
    ({
      "players/nooneelse/red/kitchen", "northwest",
      "players/nooneelse/red/ballroom", "west"
    });
}
