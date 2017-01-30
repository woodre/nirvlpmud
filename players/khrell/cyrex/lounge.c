inherit "room/room";
reset(arg) {
if(arg) return;
if(!present("Lynn Minmei")) {
move_object(clone_object("players/cyrex/minmei"), this_object());
}
set_light(1);
short_desc = "Lounge";
long_desc = "    This is the lounge where there's always excitment happening\n"+
            "however, today is not the right time.  There are drinks and\n"+
            "tables thrown about everywhere.  Bottles here and there.  You\n"+
            "seem surprised though to see that this rooms interior seems\n"+
            "intact still.  There is a stage to the middle of the room. You\n"+
            "lift up your head to see Minmei, a most beautiful lady with\n"+
            "hardly anything on....singing.  You fall in love instantly..\n\n";
dest_dir = ({"players/cyrex/barrier", "north",
 "players/cyrex/pub", "south",
});
}
