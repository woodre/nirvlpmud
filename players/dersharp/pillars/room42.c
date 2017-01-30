inherit "room/room";
int i;
reset(arg) {
        if(!present("orc")) {
        for(i=0;i<3;i++) {
           move_object(clone_object("players/dersharp/monsters/ogre"), this_object());
        }
   }
        if(!arg) {
        set_light(1);
        short_desc ="A dark corridor";
        long_desc ="A great evilness lays in wait, you can feel it.\n"+
                   "Guarded by three ogres is a hole in the floor.  It is\n"+
                   "from there that the evilness comes from.\n";
        dest_dir = ({

                "players/dersharp/pillars/room41.c", "north",
                "players/dersharp/pillars/room29.c", "down",
});
}
}
