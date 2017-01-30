/*
 wrecked_ship_hold.c
*/

inherit "room/room";

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc = "the hold of a sunken ship";
  no_castle_flag=1;
  long_desc =
    "You are in the hold of the sunken ship.\n";
  dest_dir =
    ({
      "players/nooneelse/sea/wrecked_ship_deck", "up",
    });
}
