inherit "room/room";
int i;
reset(arg) {
        if(!present("bat")) {
        for(i=0;i<5;i++) {
           move_object(clone_object("players/dersharp/monsters/bat"), this_object());
        }
   }
        if(!arg) {
                set_light(1);
        short_desc ="A musty room";
        long_desc ="The evil permeates the air as you look in this room\n"+
                   "Creatures of the Shadow Master rise up to destroy you!\n";
        dest_dir = ({

                "players/dersharp/pillars/roomst1.c", "west",
                "players/dersharp/pillars/room6.c", "northeast",
                "players/dersharp/pillars/room5.c", "north",
                "players/dersharp/pillars/room10.c", "east",
                "players/dersharp/pillars/room14.c", "south",
                });

        }
}
