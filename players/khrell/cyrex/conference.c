inherit "room/room";
reset(arg) {
if(arg) return;
set_light(1);
short_desc = "Conference Room";
long_desc = "    This room seems like it was used for some kind of gathering\n"+
            "or meeting place of the top personnel.  You notice on the wall\n"+
            "a large insignia of the Earth Defense Control.  It looks all\n"+
            "rusted and stained now...you want to polish it up, but you know\n"+
            "times a wasting.  You see another small room to the south.\n\n";
dest_dir = ({"players/cyrex/passageway", "north",
 "players/cyrex/chamber", "south",
});
}
