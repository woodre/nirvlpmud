inherit "room/room";
reset(arg) {
if(arg) return;
set_light(1);
short_desc = "Cargo Bay";
long_desc = "    You have entered the cargo bay..You see all around you\n"+
            "weapons and armors of all sorts.  In the corner you see a\n"+
            "smashed Veritech Fighter..the other end the room you see\n"+
            "some alpha and beta fighters..plus a cyclone somehow smashed\n"+
            "against them...To the north however you hear some mechanical\n"+
            "nosies..maybe there is a working machine of some sort.\n\n";
dest_dir = ({"players/cyrex/bridge", "west",
 "players/cyrex/launchpad", "north",
 "players/cyrex/shop", "south",
 "players/cyrex/hire/level1", "up",
});
}
