inherit "room/room";
int i;
reset(arg) {
        if(!present("orc")) {
        for(i=0;i<7;i++) {
           move_object(clone_object("players/dersharp/monsters/orc"), this_object());
        }
   }
        if(!arg) {
        set_light(1);
        short_desc ="A dimly lit room";
        long_desc ="Up on this second level the monsters do not seem as hard\n"+
                   "yet there are more of them.  This room is damp with bits\n"+
                   "of unidentifiable matter everywhere.\n";
        dest_dir = ({
                     "players/dersharp/pillars/room35.c", "north",
                     "players/dersharp/pillars/room40.c", "south",
});
}
}
