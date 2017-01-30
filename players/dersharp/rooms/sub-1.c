inherit "room/room";
reset(arg) {
   if (arg) return;
   short_desc="A rotten sewarway";
   long_desc ="The stench here is awful.  Looking up you see an exit in\n"+
              "the ceiling.  You are just glad to get out of this place\n";
   set_light(1);
   dest_dir =
   ({
             "players/dersharp/rooms/sub0.c", "east",
             "players/dersharp/rooms/citlav.c", "up",
   });
}
