#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  if (arg)
    return;
  set_light(1);
  short_desc = "A small road";
  long_desc = 
"You are standing on a small road which continues to the north.\n" +
"There is a meadow to the west.\n";
  dest_dir = ({
    "players/angmar/fairyland/road2", "south",
    "players/angmar/fairyland/crossing", "north",
    "players/angmar/fairyland/meadow", "west",
  });
  items = ({
    "meadow", "The lush green grass and fresh air entice you to wander over there",
    "road", "The road seems to be narrowing down",
  });
}

string realm() { return ("fairyland"); }
