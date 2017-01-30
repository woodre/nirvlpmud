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
        short_desc ="Shadow's Gate";
        long_desc ="This is the gateway to the Shadow Master's hall.  Only\n"+
                   "the bravest or most foolhardy should enter for he is\n"+
                   "powerful and very unfriendly.\n";
        dest_dir = ({
                "players/dersharp/pillars/room26.c", "north",
                "players/dersharp/pillars/room29.c", "south",
                });

        }
}
