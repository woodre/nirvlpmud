inherit "room/room";
int i;
reset(arg) {
        if(!present("wolf")) {
        for(i=0;i<4;i++) {
           move_object(clone_object("players/dersharp/monsters/wolf"), this_object());
        }
   }
        if(!arg) {
                set_light(1);
        short_desc ="Doom's alley";
        long_desc ="	The tension in the air suddenly changes for the\n"+
                   "worse.  The evil in this place is overwhelming and \n"+
                   "sense even greater evilness from the south...\n";
        dest_dir = ({

                "players/dersharp/pillars/room27.c", "east",
                "players/dersharp/pillars/room28.c", "south",
                });

        }
}
