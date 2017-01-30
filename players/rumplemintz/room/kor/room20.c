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
        short_desc = "Castle Drawbridge";
        long_desc = "     You've found the drawbridge to Kor's castle.  Fortunate for\n"+
                "you, the bridge is always kept in the down position.\n";
        dest_dir = ({

                "players/rumplemintz/room/kor/room19", "north",
                "players/rumplemintz/room/kor/castle/room1", "southwest",
                });

        }
}
