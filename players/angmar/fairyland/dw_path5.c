#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  if (arg)
    return;
  set_light(1);
  short_desc = "On a path in Darkwood";
  long_desc = 
"You are on a twisty path in the legendary Darkwood. The\n"+
"forest ends to the west.\n";
  dest_dir = ({
    "players/angmar/fairyland/behind_mountain", "west",
    "players/angmar/fairyland/dw_path4", "east",
    "players/angmar/fairyland/darkwood5", "north",
  });
  items = ({
    "west", "The forest ends, finally",
    "forest", "The forest has thinned out slightly.  Could you be out of it?  Perhaps..",
  });
}

string realm() { return ("fairyland"); }
