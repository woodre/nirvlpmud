inherit "room/room";
reset(arg) {
if(arg) return;
if(!present("Rick Hunter")) {
move_object(clone_object("players/cyrex/rickh"), this_object());
}
set_light(1);
short_desc = "Rick Hunter's Quarters";
long_desc = "    This is the quarters of Rick Hunter.  It seems that he is\n"+
            "busy at the moment daydreaming.  You see that there is hardly\n"+
            "anything left in this room but debri...you accidentally make a\n"+
            "noise and Rick turns around and glazes at you...\n\n";
dest_dir = ({"players/cyrex/passageway", "south",
});
}
