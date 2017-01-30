inherit "room/room";
int i;
reset(arg) {
  if (!arg) {
   short_desc="University Street";
   long_desc ="To the east and a little north is the university. The road \n"+
              "also continues its way to the west.  There isn't a lot of \n"+
              "activity around here but to the east there seems to be.\n";
   set_light(1);
   dest_dir =
   ({
             "players/dersharp/rooms/grey4.c", "west",
             "players/dersharp/rooms/grey6.c", "east",
   });
}
}
