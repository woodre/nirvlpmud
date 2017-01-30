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
        short_desc ="A secret corridor",
        long_desc ="This passage hasn't seen much use in the past months and\n"+
                   "the monsters are VERY hungry.\n";
        dest_dir = ({
                "players/dersharp/pillars/room44.c", "east",
                "players/dersharp/pillars/room32.c", "south",
});
}
}
