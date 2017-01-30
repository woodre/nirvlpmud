inherit "room/room";
int i;
reset(arg) {
        if(!present("warrior")) {
           for(i=0;i<10;i++) {
              move_object(clone_object("players/rumplemintz/mon/bane/skwarr2"), this_object());
        }
    }
        if(!arg) {
                set_light(1);
        short_desc = "The House of Pain";
        long_desc = "     This is not a good place to be if you are not strong.  There are\n"+
                "warriors who are pissed about the day!  RUN! RUN!\n";

        dest_dir = ({

                "players/rumplemintz/room/bane/room1", "north",
                });

        }
}
