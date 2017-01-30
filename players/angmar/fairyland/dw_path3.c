#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  if (arg)
    return;
  short_desc = "On a path in Darkwood";
  long_desc = 
"You are on a twisty path in the legendary Darkwood. You can see\n"+
"gleaming eyes stare at you from the shadows.\n";
  dest_dir = ({
    "players/angmar/fairyland/darkwood2", "north",
    "players/angmar/fairyland/dw_path2", "south",
    "players/angmar/fairyland/dw_path4", "west",
  });
  items = ({
    "eyes", "They appear red, but then disappear.  They reappear momentarily",
  });
}

string realm() { return ("fairyland"); }
