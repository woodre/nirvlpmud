inherit "room/room";

reset(arg)
{
    if (arg) return;
    set_light(1);
    short_desc = "An asteroid";
    long_desc = "Here lies the wreckage of a Klezmeer, Destructor\n"+
    "Class Star-ship.  A malfunction caused by a virus introduced by a \n"+
    "saboteur commanded the redundant Hyper Drive computers to *jump*\n"+
    "to the coordinates of this asteroid. Most of the wreckage is \n"+
    "concentrated in a crater about 2 kilometers in diameter.\n"+
    "What looks like the bridge section is miraculously somewhat intact.\n";

dest_dir = 
({
    "players/morgoth/CASTLE/asteroid4", "down",
    "players/morgoth/CASTLE/asteroid2", "west",
});
}

realm(){return "NT";}

query_temp() { return 1; }
