inherit "room/room";
int i;
reset(arg) {
        if(!present("master")) {
        move_object(clone_object("players/dersharp/monsters/shadmast"), this_object());
        }
        if(!arg) {
        set_light(1);
        short_desc ="The Shadow Master's Hall";
        long_desc ="	The light in this room does nothing to make it more\n"+
                   "enjoyable to be here.  Numerous shadows are apparent in\n"+
                   "in the dim light.  As you watch you see one of the \n"+
                   "shadows detach from the others and appear before you!\n";
        dest_dir = ({
                "players/dersharp/pillars/room28.c", "north",
                "players/dersharp/pillars/room42.c", "up",
                });

        }
}
