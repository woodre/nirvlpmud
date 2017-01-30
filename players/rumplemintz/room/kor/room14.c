inherit "room/room";
int i;
reset(arg) {
        if(!present("orc")) {
            for(i=0;i<2;i++) {
      move_object(clone_object("players/rumplemintz/mon/kor/korc"), this_object());
        }
    }
        if(!arg) {
                set_light(1);
        short_desc = "The lands of Kor";
        long_desc = "     You hae wandered so far off the path, that you've gotten\n"+
                "very lost.  You can continue on, or go back.\n";

        dest_dir = ({

                "players/rumplemintz/room/kor/room7", "northwest",
                "players/rumplemintz/room/kor/room16", "northeast",
                });

        }
}
