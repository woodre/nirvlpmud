inherit "room/room";
int i;
reset(arg) {
        if(!arg) {
                set_light(1);
         short_desc = "A small room";
         long_desc = "This room has a long unused stairwell in it leading\n"+
                     "up to the second level.  To the north is a room that\n"+
                     "you do not feel comfortable thinking about, as if \n"+
                     "some evil was there...\n";
        dest_dir = ({

                "players/dersharp/pillars/roomst5.c", "up",
                "players/dersharp/pillars/room1.c", "north",
                });

        }
}
