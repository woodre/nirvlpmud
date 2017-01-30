inherit "room/room";
int i;
reset(arg) {
        if(!present("bat")) {
        for(i=0;i<4;i++) {
           move_object(clone_object("players/dersharp/monsters/wolf"), this_object());
        }
   }
        if(!arg) {
        set_light(1);
        short_desc ="A dark corridor";
        long_desc ="The corridor suddenly becomes darker and more ominous.\n";
        dest_dir = ({
                "players/dersharp/pillars/room43.c", "west",
                "players/dersharp/pillars/room45.c", "north",
});
}
}
