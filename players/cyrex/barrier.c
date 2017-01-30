inherit "room/room";
reset(arg) {
if(arg) return;
set_light(1);
short_desc = "Barrier Room";
long_desc = "    Once you enter this room, you are amazed instanly by all\n"+
            "the advanced technology you see.  There are huge monitors on\n"+
            "the east wall which show the SDF-1 transformed into Robot mode\n"+
            "and ship mode.  All status readouts are still functioning.  You\n"+
            "take a closer look at one of the panels and find the intruder\n"+
            "light flashing...you wonder who or what it could be...\n\n";
dest_dir = ({"players/cyrex/passageway", "west",
 "players/cyrex/rfquarters", "north",
 "players/cyrex/lounge", "south",
 "players/cyrex/bridge", "east",
});
}
