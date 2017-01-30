inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("The jungle");
  long_desc=
    "You are in the jungle. Trees surround you everywhere.\n"+
    "The ground is damp and the air is moist. The branches\n"+
    "of the trees blockout the sun. You must venture deeper\n"+
    "into the woods for you to find your way back home.\n";
  dest_dir=
    ({
      "/players/bagera/jungle/room14.c", "north",
      "/players/bagera/jungle/room30.c", "south",
      "/players/bagera/jungle/room21.c", "west",
      "/players/bagera/jungle/room23.c", "east"
    });
  }
