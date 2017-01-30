inherit "room/room";
reset(arg) {
if(arg) return;
if(!present("Roy Fokker")) {
move_object(clone_object("players/cyrex/royf"), this_object());
}
set_light(1);
short_desc = "Roy Fokker's Quarters";
long_desc = "    As you enter this room, you notice this must be the room of\n"+
            "a hero or something.  You see medals all about the floor,\n"+
            "pictures, awards and so forth.  You see a tall man standing n\n"+
            "near a desk trying to organize files.  You speak and he turns\n"+
            "and only stares at you and continues on with his work...You\n"+
            "wonder if you should leave...\n\n";
dest_dir = ({"players/cyrex/barrier", "south",
});
}
