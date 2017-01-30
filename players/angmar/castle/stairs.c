inherit "room/room";

void
reset(status arg) {
  if (arg)
    return;
  set_light(1);
  short_desc = "Top of stairs";
  long_desc = 
    "You are at the top of a long staircase going down into the lower\n" +
    "regions of the castle.  You peer into the darkness below, but\n" +
    "can see nothing.\n";
  dest_dir = ({
    "players/angmar/castle/inside", "north",
    "players/angmar/castle/midstairs", "down",
  });
  items = ({
    "stairs", "They look slippery, but it should be relatively safe climbing down",
    "staircase", "The staircase winds its way into the nether regions of the castle",
    "castle", "The castle seems eerie as it envelopes you in its dark folds",
  });
}
