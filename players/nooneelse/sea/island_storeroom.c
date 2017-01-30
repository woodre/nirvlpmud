/*
 island_storroom.c
*/

inherit "room/room";

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc = "storeroom";
  no_castle_flag=1;
  long_desc =
    "This small room was carved out of the solid rock!\n";
  dest_dir =
    ({
      "players/nooneelse/sea/island_hall", "west",
    });
  if (!present("bag")) move_object(clone_object("/obj/bag"), this_object());
}
