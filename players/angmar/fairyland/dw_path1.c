#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  if (arg)
    return;
  set_light(1);
  short_desc = "On a path in Darkwood";
  long_desc = 
"You are on a twisty path in the legendary Darkwood.  Many adventurers\n" +
"have been killed here.\n";
  dest_dir = ({
    "players/angmar/fairyland/dw_path2", "north",
    "players/angmar/fairyland/darkw_entrance", "west",
  });
  items = ({
    "path", "The path twists and turns as it weaves its way into Darkwood",
    "darkwood", "The mystical forest makes you shudder as it emanates evil",
  });
}

string realm() { return ("fairyland"); }
