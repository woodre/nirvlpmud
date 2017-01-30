/*
 island_hall.c
*/

inherit "room/room";

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc = "hall";
  no_castle_flag=1;
  long_desc =
    "This clean hallway was carved out of the solid rock!\n";
  dest_dir =
    ({
      "players/nooneelse/sea/island_dock", "down",
      "players/nooneelse/sea/island_diving_room", "west",
      "players/nooneelse/sea/island_storeroom", "east",
      "players/nooneelse/sea/island_captain_room", "south",
      "players/nooneelse/sea/beach_1", "northeast",
    });
}
