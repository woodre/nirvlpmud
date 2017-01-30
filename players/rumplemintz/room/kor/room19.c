inherit "room/room";
reset(arg) {
        if(!arg) {
                set_light(1);
        short_desc = "Castle Passage";
        long_desc = "     You have recovered the path, and it looks like it leads to\n"+
                "a castle.  Most likely, this is Kor's castle.  It's probably not\n"+
                "very desirable to be in, but i guess if you like that sort of thing.\n";

        dest_dir = ({

                "players/rumplemintz/room/kor/room18", "north",
                "players/rumplemintz/room/kor/room16", "west",
                "players/rumplemintz/room/kor/room20", "south",
                });

        }
}
