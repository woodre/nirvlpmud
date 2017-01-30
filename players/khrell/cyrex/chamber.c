inherit "room/room";
reset(arg) {
if(arg) return;
set_light(0);
short_desc = "Hearing Chamber";
long_desc = "    This room resembles a court room of the past...There are\n"+
            "three seats at what used to be the head of this trapezoidial\n"+
            "table and one seat at the base.  All around you see video\n"+
            "cameras(or what used to be)scattered across the room.  This\n"+
            "must have been a real intense and nerve shattering room to be\n"+
            "in...for those who are on trial that is..\n\n";
dest_dir = ({"players/cyrex/conference", "north",
 "players/cyrex/msquarters", "west",
});
}
