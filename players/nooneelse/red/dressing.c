/*
 dressing.c
*/

inherit "room/room";

reset(arg) {
  if (arg) return;

  set_light(0);
  short_desc = "dressing room";
  no_castle_flag=1;
  long_desc =
    "Two small tables with chairs and attached mirrors are the only\n"
    + "items of furniture in this room.  A long rack against one wall\n"
    + "holds many robes and suits of gentleman's clothing and another\n"
    + "rack on the opposite wall holds many items of lady's clothing.\n"
    + "Unfortunately, all the clothing is so decayed, that none of it\n"
    + "is useful.\n";
  items =
    ({
      "tables", "Two small wooden tables with a mirror attached to the back.",
      "mirror", "It doesn't seem to work.  You can't see yourself!",
      "mirrors", "They don't seem to work.  You can't see yourself!",
      "chairs", "You see two wooden chairs with padded seats.",
      "rack", "It is an ordinary wooden clothes rack.",
      "robe", "Moth-eaten old robe.",
      "robes", "Moth-eaten old robes.",
      "suits", "Tattered old man's clothing.",
      "clothing", "Tattered old man's and woman's clothing.",
    });
  dest_dir =
    ({
      "players/nooneelse/red/bedroom2", "north",
      "players/nooneelse/red/sunroom", "east",
      "players/nooneelse/red/bedroom1", "west",
    });
}
