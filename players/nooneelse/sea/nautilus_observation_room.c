/*
 nautilus_observation_room.c -
                      look out the ports at the scenery from the nautilus
*/

inherit "room/room";

init() {
  ::init();

  add_action("sit",    "sit");
}

sit() {
  write("The soft leather squishes down a little as you get comfortable.\n");
  say(this_player()->query_name()+" sits back on one of the couches.\n");
  return 1;
}

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc=("observation room");
  no_castle_flag=1;
  long_desc=
    "This is a large room with several couches facing the observation ports.\n";
  items=
    ({
      "couches", "They look very comfortable.",
      "couch", "It looks very comfortable.",
      "ports", "They are large, glass windows, used to watch the sea bottom.",
      "port", "It is a large, glass window, used to watch the sea bottom.",
    });
  dest_dir=
    ({
      "players/nooneelse/sea/nautilus_below_deck", "aft",
    });
  return;
}
