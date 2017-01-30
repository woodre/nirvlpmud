#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  if (arg)
    return;
  set_light(1);
  short_desc = "Edge of the woods";
  long_desc = 
"You are at the edge of the beech woods. You can hear the sounds of\n" +
"birds singing.\n";
  dest_dir = ({
    "players/angmar/fairyland/edge1", "east",
    "players/angmar/fairyland/beech2", "south",
  });
  items = ({
    "edge", "The road blends into the woods here",
    "woods", "Dozens of beech trees, as far as the eye can see",
    "beech trees", "Magnificent fauna, watching the land",
    "sounds", "The sounds of a bird who is content",
  });
}

string realm() { return ("fairyland"); }
