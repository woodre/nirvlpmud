#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  if (arg)
    return;
  set_light(1);
  set_light(1);
  short_desc = "The foot of Misty Mountain";
  long_desc = 
"Misty Mountain towers high before you.  You feel very small.\n";
  dest_dir = ({
    "players/angmar/fairyland/path2", "south",
    "players/angmar/fairyland/mountain", "up",
  });
  items = ({
    "misty mountain", "The mountain is huge, but you think you can climb up",
    "mountain", "The mountain is huge, but you think you can climb up",
  });
}

string realm() { return ("fairyland"); }
