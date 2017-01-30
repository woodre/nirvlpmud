inherit "room/room";
int i;
reset(arg) {
        if(!present("rider")) {
      move_object(clone_object("players/rumplemintz/mon/kor/wrider"), this_object());
    }
        if(!arg) {
                set_light(1);
        short_desc = "Deep in Kor territory";
        long_desc = "     You've wandered deep into Kor territory.  At first they didn't\n"+
                "mind you here, but they are becoming restless and aggressive.\n";
        dest_dir = ({

                "players/rumplemintz/room/kor/room7", "southwest",
                "players/rumplemintz/room/kor/room16", "southeast",
                });

        }
}
