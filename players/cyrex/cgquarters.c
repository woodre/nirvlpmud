inherit "room/room";
reset(arg) {
if(arg) return;
if(!present("Captain Gloval")) {
move_object(clone_object("players/cyrex/gloval"), this_object());
}
set_light(1);
short_desc = "Captain Gloval's Quarters";
long_desc = "    This is the quarter's of Captain Gloval.  The captain is an\n"+
            "old wise man.  He has led the Earth Defense Forces through\n"+
            "practically all the battles engaged against the Zentradi's.\n"+
            "Now he waits patiently..the battle is over for now.. but he knows\n"+
            "the war is just begining.....new enemies and threats are\n"+
            "forming but he is in no shape to fight again without a new ship\n"+
            "to command..he waits for this day... He is a man full of pride\n"+
            "and integrity.\n\n";
dest_dir = ({"players/cyrex/cgprivate", "west",
});
}
