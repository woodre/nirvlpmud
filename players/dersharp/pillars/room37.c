inherit "room/room";
int i;
reset(arg) {
        if(!present("skeleton")) {
        for(i=0;i<5;i++) {
           move_object(clone_object("players/dersharp/monsters/skel"), this_object());
        }
   }
        if(!arg) {
        set_light(1);
        short_desc ="A dimly lit room";
        long_desc ="Up on this second level the monsters do not seem as hard\n"+
                   "yet there are more of them.  This room is damp with bits\n"+
                   "of unidentifiable matter everywhere.  Along the north\n"+
                   "wall there seems to be something different.\n";
        dest_dir = ({
                "players/dersharp/pillars/room34.c", "north",
                "players/dersharp/pillars/room36.c", "west",
});
}
}
