inherit "room/room";
reset(arg)
{
    if (arg) return;
    short_desc = "A crater";
    long_desc = "The bottom of the crater stretches out into the dark distance.\n"+
    "The intact portion of the bridge stands in front.  The wreckage\n"+
    "looms above blocking out the stars. There appears to be no way to enter\n"+
    "directly into the wreckage but perhaps it could be climbed.\n";

    dest_dir = 
    ({
        "players/morgoth/CASTLE/asteroid4", "up",
    });
}

init()
{
    ::init();
    add_action("climb_bridge", "climb");
}

climb_bridge()
{
    write("You climb up the wreckage !\n");
    call_other(this_player(), "move_player", "climb#players/morgoth/CASTLE/bridge2");
    say(call_other(this_player(), "query_name") + " climbs up the wreckage.\n");
    return 1;
}

realm(){return "NT";}
