inherit "room/room";
reset(arg) {
if(arg) return;
set_light(1);
short_desc = "Investigation Room";
long_desc = "    Upon entering this room, you immediately notice all the \n"+
            "maps and plans and files of the Zentradi's scattered about the\n"+
            "room.  You look through some of the papers and find nothing of\n"+
            "interest.  (Maybe later there will be....)The huge walls are \n"+
            "all covered with blast holes...you wonder if someone was after\n"+
            "something.....\n\n";
dest_dir = ({"players/cyrex/corridor", "north",
 "players/cyrex/office", "south",
});
}
