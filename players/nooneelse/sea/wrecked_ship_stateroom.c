/*
 wrecked_ship_stateroom.c
*/

inherit "room/room";

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc = "the stateroom of a sunken ship";
  no_castle_flag=1;
  long_desc =
    "You are in a once fabulously decorated cabin.  It must have been\n"+
    "the captains.\n";
  dest_dir =
    ({
      "players/nooneelse/sea/wrecked_ship_cabin", "fore",
    });
}
