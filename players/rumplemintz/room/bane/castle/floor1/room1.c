inherit "room/room";
#define ADD(XXX,YYY) add_action("XXX"); add_verb("YYY");
reset(arg){
        if(!arg){
        set_light(1);
        short_desc="Bane's Lobby";
        long_desc="  You have entered Lord Bane's Castle.  You stand in the lobby, and\n"+
                "even though there aren't any monsters here, you feel watched.  You have\n"+
                "a strange feeling that you shouldn't be here, everything about this\n"+
                "place is dismal and gloomy.  You'd hate to think what Bane himself\n"+
                "would do if he caught you wandering around his castle...\n";
        dest_dir=({
                "players/rumplemintz/room/bane/castle/outside","leave",
                "players/rumplemintz/room/bane/castle/floor1/room2","east",
                "players/rumplemintz/room/bane/castle/floor1/room8","south",
                "players/rumplemintz/room/bane/castle/floor1/room9","southeast",
        });
        }
}
