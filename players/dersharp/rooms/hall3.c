inherit "room/room";
reset(arg) {
   if (arg) return;
   short_desc="A wide hallway";
   long_desc ="This is the main corridor that goes through the Citadel. \n"+
              "The main part of the Citadel lies above, but many interesting\n"+
              "people can be found on this level.\n";
   set_light(1);
   dest_dir =
   ({
             "players/dersharp/rooms/citlav.c", "east",
             "players/dersharp/rooms/hall2.c", "south",
             "players/dersharp/rooms/hall4.c", "north",
             "players/dersharp/rooms/ante5.c", "west",
   });
}
