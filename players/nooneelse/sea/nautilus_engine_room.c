/*
 nautilus_engine_room.c - the engine room of the nautilus
*/

inherit "room/room";

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc=("engine room");
  no_castle_flag=1;
  long_desc=
    "This is a large, but cramped, room filled with huge machinery.\n"+
    "One of them has a thick translucent plate over a port.  You hear\n"+
    "and feel, a deep throbbing.\n";
  items=
    ({
      "machinery", "They are massive, incomprehensible devices.",
      "machines", "They are massive, incomprehensible devices.",
      "machine", "It is a massive, incomprehensible device.",
      "port", "It is a small, crystal window, used to watch the "+
              "operation of the machine.\n"+
              "Inside, you can see bright flashes of various colors.",
    });
  dest_dir=
    ({
      "players/nooneelse/sea/nautilus_below_deck", "forward",
    });
  return;
}
