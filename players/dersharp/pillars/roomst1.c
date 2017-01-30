inherit "room/room";
int i;
reset(arg) {
        if(!arg) {
                set_light(1);
         short_desc = "Starting place";
        long_desc ="Looking at your surroundings you notice a stone\n"+
                   "stairway leading up into darkness.  To the west and\n"+
                   "east you hear squeeking while to the south you hear\n"+
                   "nothing.  !!CAUTION!! the first level of this dugeon\n"+
                   "is more difficult than the second...So newbies of levels\n"+
                   "1-4 should probably head upstairs.  Others and the more\n"+
                   "daring newbies are welcome here.\n";
        dest_dir = ({

                "players/dersharp/pillars/room4.c", "north",
                "players/dersharp/pillars/room8.c", "west",
                "players/dersharp/pillars/room9.c", "east",
                "players/dersharp/pillars/room13.c", "south",
                "players/dersharp/pillars/roomst2.c", "up",
                });

        }
}
