/*
  g_path_crypte_stairs.c
*/

inherit "room/room";

realm() { return "NT"; }

reset(arg) {
  if (arg) return 0;

  set_light(0);
  short_desc="Dark stairs in a crypt";
  long_desc="You are in a dark stariwell of a dark crypt.  Dark stairs lead\n"+
           "down into the earth and up to the inner room.\n";
  items=({
          "stairs",
            "Stairs carved out of solid granite, leading up and down",
        });
  dest_dir=({
             "players/nooneelse/graveyard/g_path_crypte_lower", "down",
             "players/nooneelse/graveyard/g_path_crypte_inner", "up",
           });
}
