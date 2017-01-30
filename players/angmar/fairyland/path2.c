#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  if (arg)
    return;
  set_light(1);
  set_light(1);
  short_desc = "The path to Misty Mountain";
  long_desc = 
"You are on the path to Misty Mountain.  You can see the might\n" +
"of the mountain encompassed in the sheer size of the object.\n" +
"It has stood for eons, and few know of the treasures, secrets,\n" +
"and pitfalls within.\n";
  dest_dir = ({
    "players/angmar/fairyland/mountain_foot", "north",
    "players/angmar/fairyland/path1", "east",
  });
  items = ({
    "path", "The path seems to be less worn now, as if few had travelled it",
    "misty mountain", "The sheer beauty of the spectacle amazes you",
    "mountain", "The sheer beauty of the spectacle amazes you",
  });
}

string realm() { return ("fairyland"); }
