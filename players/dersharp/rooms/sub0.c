inherit "room/room";
reset(arg) {
   if (arg) return;
   short_desc="A rotten sewarway";
   long_desc ="This is one of the highways used by the thieves and beggars\n"+
              "of Greyhawk to get into the Citadel.  Thankfully you don't\n"+
              "see any of them around....yet.\n";
   set_light(1);
   dest_dir =
   ({
             "players/dersharp/rooms/grey0.c", "up",
             "players/dersharp/rooms/sub-1.c", "west",
   });
}
