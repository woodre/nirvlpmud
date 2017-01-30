inherit "room/room";

reset(arg) {
        if(!arg) {
                set_light(1);
         short_desc = "Mountain path to the Storm Giants.";
        long_desc = "     This is the beginning of a path that leads to the Storm Giants.\n"+
                "They are a tough breed of giants who are aggressive and unforgiving.\n"+
                "You might be wise to turn back now, but nobody has ever accused you\n"+
                "of being the wise type have they...\n";

        dest_dir = ({

                "players/rumplemintz/room/stlanding", "east",
                 "players/rumplemintz/room/storm/room2", "northwest",
      "players/rumplemintz/room/storm/room3", "west",
      "players/rumplemintz/room/storm/room4", "southwest",
                });

        }
}
