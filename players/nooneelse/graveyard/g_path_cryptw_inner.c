/*
  g_path_cryptw_inner.c
*/

inherit "room/room";

realm() { return "NT"; }

reset(arg) {
  if (arg) return 0;

  set_light(0);
  short_desc="Inner room of a crypt";
  long_desc="You are in an inner room of a dark crypt.\n"+
            "Dark stairs lead down into the earth and the arch\n"+
            "leads out to the entrance.\n";
  items=({
          "arch", "It is door-sized opening in the east wall",
          "stairs", "Stairs carved out of solid granite, leading down",
        });
  dest_dir=({
             "players/nooneelse/graveyard/g_path_cryptw_stairs", "down",
             "players/nooneelse/graveyard/g_path_cryptw", "west",
           });
}
