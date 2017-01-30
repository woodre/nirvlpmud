inherit "room/room";
int i;
reset(arg) {
        if(!present("goblin")) {
        for(i=0;i<5;i++) {
           move_object(clone_object("players/dersharp/monsters/gob"), this_object());
        }
   }
        if(!arg) {
        set_light(1);
        short_desc ="A dark corridor";
        long_desc ="The corridor suddenly becomes darker and more ominous.\n"+
                   "To the south you feel a great evil in waiting.\n";
        dest_dir = ({
                "players/dersharp/pillars/room40.c", "east",
                "players/dersharp/pillars/room41.c", "south",
});
}
}
