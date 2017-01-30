inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("Deep jungle");
  long_desc=
    "You see the corner of a stone structure. You can\n"+
    "see a door off to the south. The vines cover so much\n"+
    "it is hard to distinguish. A wind whips around the\n"+
    "corner and pushes you back some. The stone wall\n"+
    "continues to the south and west. There is a clearing\n"+
    "to the north and you hear a rumbling sound from that general\n"+
    "direction.\n";
  dest_dir=
    ({
      "/players/bagera/jungle/room37.c", "northeast",
      "/players/bagera/jungle/room36.c", "north",
      "/players/bagera/jungle/room45.c", "south"
    });
  }
