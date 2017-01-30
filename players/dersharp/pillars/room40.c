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
        short_desc ="A dark corridor";
        long_desc ="The corridor suddenly becomes darker and more ominous.\n"+
                   "The corridor to the west seems darker than this one.\n";
        dest_dir = ({
                "players/dersharp/pillars/room38.c", "north",
                "players/dersharp/pillars/room39.c", "west",
});
}
}
