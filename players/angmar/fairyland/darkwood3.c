#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  if (arg)
    return;
  set_light(1);
  short_desc = "Somewhere deep inside Darkwood";
  long_desc = 
"You are walking somewhere deep inside the Darkwood. Are you\n" +
"lost? Will you ever see your mummy again?\n";
  dest_dir = ({
    "players/angmar/fairyland/darkwood5", "west",
    "players/angmar/fairyland/darkwood2", "east",
    "players/angmar/fairyland/dw_path4", "south",
  });
}

string realm() { return ("darkwood"); }
