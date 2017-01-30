inherit "room/room";
int i;
reset(arg) {
        if(!present("rider")) {
                move_object(clone_object("players/rumplemintz/mon/kor/wrider"), this_object());
    }
        if(!arg) {
                set_light(1);
        short_desc = "The wilderness of Kor";
        long_desc = "     You wander through the land of Kor, and come across two orcs.\n"+
                "You wonder if they're friendly, or evil.  Take a listen and see...\n";
        dest_dir = ({

                "players/rumplemintz/room/kor/room11", "southwest",
                  "players/rumplemintz/room/kor/room17.c", "southeast",
                });

        }
}
