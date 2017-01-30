/*
 hall.c
*/

inherit "room/room";

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc = "hall";
  no_castle_flag=1;
  long_desc =
    "This hallway is lined with cracked and dusty paintings.  Spaced between\n"+
    "each is an elaborate wrought iron candle sconce with flickering black\n"+
    "candles.\n";
  items =
    ({
      "floor", "The stone floor is covered with dust.",
      "paintings",
        "The paintings seem to be of the former owners of this mansion.",
      "painting",
        "The painting seems to be of the former owner of this mansion.",
      "sconce", "An elaborately carved metal candle holder bolted to the wall.",
      "sconces", "An elaborately carved metal candle holder bolted to the wall.",
      "candle", "A thick black candle burning with a pale light.",
      "candles", "Thick black candles burning with a pale light.",
    });
  dest_dir =
    ({
      "players/nooneelse/redentry", "south",
      "players/nooneelse/red/sunroom", "north",
      "players/nooneelse/red/parlor", "west",
      "players/nooneelse/red/sitting", "east",
    });
}
