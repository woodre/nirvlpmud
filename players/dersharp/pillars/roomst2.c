inherit "room/room";
int i;
reset(arg) {
        if(!arg) {
                set_light(1);
         short_desc = "Second level";
        long_desc ="	The second level of the dungeon appears to be\n"+
                   "brighter and less threatening than the first level.\n"+
                   "However it can still be dangerous.\n";
        dest_dir = ({

                "players/dersharp/pillars/roomst1.c", "down",
                "players/dersharp/pillars/room30.c", "south",
                });

        }
}
