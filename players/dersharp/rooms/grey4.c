inherit "room/room";
reset(arg) {
   if (arg) return;
   short_desc="Grey Street";
   long_desc ="This is the northern end of Grey street.  Another road\n"+
              "intersects this one here.  To the east and west lie \n"+
              "University Street.  Far to the west you see a large palace\n"+
              "rising up from the filth around you. To the east and \n"+
              "slightly north is the university.  South you will find \n"+
              "the main town....full of surprises.\n";
   set_light(1);
   dest_dir =
   ({
             "players/dersharp/rooms/grey3.c", "west",
             "players/dersharp/rooms/grey5.c", "east",
             "players/dersharp/rooms/grey10.c", "south",
             "players/dersharp/rooms/greyhawke.c", "north",
   });
}
