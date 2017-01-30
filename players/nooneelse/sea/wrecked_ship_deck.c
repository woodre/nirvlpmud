/*
 wrecked_ship_deck.c
*/

inherit "room/room";

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc = "the deck of a sunken ship";
  no_castle_flag=1;
  long_desc =
    "You are at the bottom of a clear, calm sea, standing on\n"+
    "the deck of a wrecked sailing ship.\n";
  dest_dir =
    ({
      "players/nooneelse/sea/sea_15", "leave",
      "players/nooneelse/sea/wrecked_ship_hold", "down",
      "players/nooneelse/sea/wrecked_ship_cabin", "aft",
    });
}
