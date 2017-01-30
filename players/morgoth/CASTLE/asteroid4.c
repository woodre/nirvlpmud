inherit "room/room";

reset(arg)
{
    if (arg) return;
    set_light(1);
    short_desc = "A crater";
    long_desc = "The side of the crater is steep and rocky.  The loose bits\n"+
     "of rock make the way down very treacherous... The ground below is scorched.\n"+
    "The wreckage of the Klezmeer star ship is in clear view now.\n";

    dest_dir = 
    ({
        "players/morgoth/CASTLE/bridge1", "down",
        "players/morgoth/CASTLE/asteroid3", "up",
    });
}

realm(){return "NT";}
