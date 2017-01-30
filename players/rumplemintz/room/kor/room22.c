inherit "room/room";
reset(arg) {
        if(!arg) {
                set_light(1);
        short_desc = "The wilderness of Kor";
        long_desc = "     You have wandered off the beaten path, who knows what you'll\n"+
                "find out here.\n";
        dest_dir = ({

                "players/rumplemintz/room/kor/room21", "north",
                "players/rumplemintz/room/kor/room17", "west",
                });

        }
}
