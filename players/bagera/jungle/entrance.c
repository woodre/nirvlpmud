/* Added an exit, [5.24.01] - Vertebraker */
inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("The Jungle Book");
  long_desc=
    "Welcome to 'The Jungle Book'. If you are a fan of Walt\n"+
    "Disney and are a kid at heart, the you will enjoy this\n"+
    "trip into the jungle. Come back and see us, ya hear!\n";
  dest_dir=
    ({
      "/players/bagera/jungle/room5.c", "south",
      "/room/forest4.c", "exit",
    });
  }
