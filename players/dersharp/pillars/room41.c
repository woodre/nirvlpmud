inherit "room/room";
int i;
reset(arg) {
        if(!present("troglodyte")) {
        for(i=0;i<4;i++) {
        move_object(clone_object("players/dersharp/monsters/trog"), this_object());
        }
   }
        if(!arg) {
        set_light(1);
        short_desc ="A dark corridor";
        long_desc ="A great evilness lays in wait, you can feel it.\n"+
                   "The sense gets stronger as you move south.\n";
        dest_dir = ({

                "players/dersharp/pillars/room39.c", "north",
                "players/dersharp/pillars/room42.c", "south",
});
}
}
