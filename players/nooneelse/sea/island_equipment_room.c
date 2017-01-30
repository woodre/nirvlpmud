/*
 island_equipment_room.c
*/

inherit "room/room";

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc = "Equipment Room";
  no_castle_flag=1;
  long_desc =
    "This room was carved out of the solid rock!  You don't see\n"+
    "anything special about it.  Maybe it's just used to store equipment.\n";
  dest_dir =
    ({
      "players/nooneelse/sea/island_diving_room", "north",
    });
  if (!present("diving suit")) {
    move_object(clone_object("players/nooneelse/sea/diving_suit"),
                this_object());
    move_object(clone_object("players/nooneelse/sea/diving_suit"),
                this_object());
  }
}
