inherit "room/room";
int i;
reset(arg) {
        if(!present("bat")) {
        for(i=0;i<4;i++) {
           move_object(clone_object("players/dersharp/monsters/bat"), this_object());
        }
   }
        if(!arg) {
                set_light(1);
        short_desc ="A dimly lit room";
        long_desc ="Up on this second level the monsters do not seem as hard\n"+
                   "yet there are more of them.  This room is damp with bits\n"+
                   "of unidentifiable matter everywhere.\n";
        dest_dir = ({
                "players/dersharp/pillars/room33.c", "southwest",
                "players/dersharp/pillars/room32.c", "east",
                });

        }
}
