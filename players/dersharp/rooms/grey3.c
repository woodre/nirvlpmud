inherit "room/room";
reset(arg) {
   if (arg) return;
   short_desc="University Street";
   long_desc ="You are travelling along University street at its western end\n"+
              "and see the Citadel looming to the west of you.  There are\n"+
              "citizens walking around here trying to get a glimpse of the\n"+
              "leaders of Greyhawk...but to no avail.\n";
   set_light(1);
   dest_dir =
   ({
		"players/dersharp/rooms/grey1.c","west",
             "players/dersharp/rooms/grey4.c", "east",
   });
}
