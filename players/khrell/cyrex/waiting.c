inherit "room/room";
reset(arg) {
if(arg) return;
if(!present("machine")) {
move_object(clone_object("players/cyrex/private/pepsimachine"), this_object());
}
set_light(1);
short_desc = "Waiting Room";
long_desc = "    You have entered a room where you see nice comfortable\n"+
            "sofas and recliners.  You are tempted to relax and sleep for a\n"+
            "while after all the adventures you've been through.  Although \n"+
            "everything seems all out of place(probably due to the crash)you\n"+
            "wonder about how this might all have looked liked when all was\n"+
            "at its prime and glory.  There is a familiar looking machine\n"+
            "in the far corner of the room.  It still looks and sounds\n"+
            "operational judging by the faint glow and humming sounds\n"+
            "eminating from it.\n\n";
dest_dir = ({"players/cyrex/corridor", "south",
});
}
