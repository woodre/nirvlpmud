inherit "room/room";
int i;
reset(arg) {
        if(!present("orc")) {
        for(i=0;i<5;i++) {
           move_object(clone_object("players/dersharp/monsters/orc"), this_object());
        }
   }
        if(!arg) {
                set_light(1);
        short_desc ="A musty room";
        long_desc ="The evil permeates the air as you look in this room\n"+
                   "Creatures of the Shadow Master rise up to destroy you!\n";
        dest_dir = ({

                "players/dersharp/pillars/room15.c", "north",
                "players/dersharp/pillars/room18.c", "west",
                "players/dersharp/pillars/room23.c", "south",
                });

        }
}
