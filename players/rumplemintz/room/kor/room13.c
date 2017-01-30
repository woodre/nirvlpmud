inherit "room/room";
reset(arg) {
        if(!arg) {
                set_light(1);
        short_desc = "A dead End";
        long_desc = "     You have wandered into a dead end.  The only exit is the\n"+
                "way you came from.\n";

        dest_dir = ({

                "players/rumplemintz/room/kor/room7", "west",
                });

        }
}
