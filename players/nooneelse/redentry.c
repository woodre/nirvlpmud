/*
 redentry.c
*/

inherit "room/room";

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc = "foyer";
  no_castle_flag=1;
  long_desc =
    "This small entrance hall has been long unused.  Thick dust carpets the\n"
    + "floor.  To either side of the doorway stand antique suits of armour.\n"
    + "Their great age renders them good only for display.  The torches\n"
    + "set in the walls provide good light and deep shadows.\n";
  items =
    ({
      "floor", "The floor is covered with dust.",
      "suits", "All the straps, buckles and rivets are in need of repair.",
      "armour", "All the straps, buckles and rivets are in need of repair.",
      "torch", "It is a brightly burning torch, bolted to the wall.",
      "torches", "They are brightly burning torches, bolted to the wall.",
      "shadow", "It is deep and dark.  You wonder what could be lurking there.",
      "shadows",
        "They are deep and dark.  You wonder what could be lurking in them.",
    });
  dest_dir =
    ({
      "players/nooneelse/dim", "south",
      "players/nooneelse/red/hall", "north",
    });
}
