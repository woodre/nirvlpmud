inherit "room/room";
reset(arg) {
        if(!arg) {
                set_light(1);
        short_desc = "A Lighter area";
        long_desc = "     The area around here is lighter, and more visible.  You \n"+
                "welcome the sight of the morning sun, glistening with the dew on the\n"+
                "grass.  Wait a minute, this is Nirvana, not Genocide!\n";

        dest_dir = ({

                "players/rumplemintz/room/kor/room14", "southwest",
                "players/rumplemintz/room/kor/room12", "northwest",
                "players/rumplemintz/room/kor/room18", "northeast",
                "players/rumplemintz/room/kor/room19", "east",
                });
        }
}
