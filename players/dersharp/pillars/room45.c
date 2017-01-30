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
        long_desc ="A great evilness lays in wait, you can feel it.\n";
        dest_dir = ({

                "players/dersharp/pillars/room46.c", "west",
                "players/dersharp/pillars/room44.c", "south",
});
}
}
