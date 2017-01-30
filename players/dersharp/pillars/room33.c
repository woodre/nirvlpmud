inherit "room/room";
int i;
reset(arg) {
        if(!present("zombie")) {
        for(i=0;i<3;i++) {
        move_object(clone_object("players/dersharp/monsters/zomb"), this_object());
        }
   }
        if(!arg) {
        set_light(1);
        short_desc ="A dimly lit room";
        long_desc ="Up on this second level the monsters do not seem as hard\n"+
                   "yet there are more of them.  This room is damp with bits\n"+
                   "of unidentifiable matter everywhere.\n";
        dest_dir = ({

                "players/dersharp/pillars/room30.c", "north",
                "players/dersharp/pillars/room31.c", "northeast",
                "players/dersharp/pillars/room34.c", "east",
                "players/dersharp/pillars/room36.c", "south",
                });

        }
}
