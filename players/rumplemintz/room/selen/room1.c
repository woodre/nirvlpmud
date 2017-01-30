inherit "room/room";

reset(arg) {
        if(!arg) {
                set_light(1);
        short_desc = "Entrance to the Land of the Selentines";
         long_desc = "     This is the Land of the Selentines.  They are at peace with\n"+
                "everyone except the Orcs of Kor, and there gates are wide open.  You\n"+
                "might see an occasional Infantry unit wandering, but they mean you no\n"+
                "harm.  They are watching for the Orcs!\n";

        dest_dir = ({

                "players/rumplemintz/room/slanding", "northwest",
                });

        }
}
