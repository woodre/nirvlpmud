#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  if (arg)
    return;
  set_light(1);
  short_desc = "On a path in Darkwood";
  long_desc = 
"You are walking on a twisty path in the legendary Darkwood. You are\n"+
"lucky to have survived so far.\n";
  dest_dir = ({
    "players/angmar/fairyland/darkwood3", "north",
    "players/angmar/fairyland/dw_path5", "west",
    "players/angmar/fairyland/dw_path3", "east",
    "players/angmar/fairyland/darkwood4", "south",
  });
  items = ({
    "path", "The path is becoming more and more faint.  Best hope you do not lose it",
  });
}

string realm() { return ("fairyland"); }
