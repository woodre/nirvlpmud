inherit "room/room";
reset(arg) {
if(arg) return;
set_light(0);
short_desc = "Captain Gloval's Private room";
long_desc = "    You have entered the study of Captain Gloval.  This room\n"+
            "has special memories for the Captain.  You see on his walls\n"+
            "the framed pictures of his crew having some cheers after a\n"+
            "victory and pictures of sad moments when a crew member is\n"+
            "fatally wounded.  You see another room towards the east end..\n"+
            "maybe the Captain is in there...\n\n";
dest_dir = ({"players/cyrex/bridge", "north",
 "players/cyrex/cgquarters", "east",
});
}
