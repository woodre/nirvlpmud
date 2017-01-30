inherit "room/room";
reset(arg) {
   if (arg) return;
   short_desc="University Street";
   long_desc ="The Citadel fairly looms above you from this vantage point.\n"+
              "The salesmen have been replaced by Citadel guards who patrol\n"+
              "the area thoroughly.  To the west you believe you can find a\n"+
              "way into the Citadel...\n";
   set_light(1);
   dest_dir =
   ({
             "players/dersharp/rooms/grey0.c", "west",
             "players/dersharp/rooms/grey3.c", "east",
   });
}
