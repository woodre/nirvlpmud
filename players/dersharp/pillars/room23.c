inherit "room/room";
int i;
reset(arg) {
        if(!present("ogre")) {
        for(i=0;i<3;i++) {
           move_object(clone_object("players/dersharp/monsters/ogre"), this_object());
        }
   }
        if(!arg) {
                set_light(1);
        short_desc ="A musty room";
        long_desc ="The evil permeates the air as you look in this room\n"+
                   "Creatures of the Shadow Master rise up to destroy you!\n";
        dest_dir = ({

                "players/dersharp/pillars/room19.c", "north",
                });

        }
}
