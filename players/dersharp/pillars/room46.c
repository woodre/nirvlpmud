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
                   "A band of ogres hold sway here, beware they are tough!\n";
        dest_dir = ({

                "players/dersharp/pillars/roomst5.c", "north",
                "players/dersharp/pillars/room45.c", "east",
});
}
}
