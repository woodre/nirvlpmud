inherit "room/room";

reset(arg)
{
    if (arg) return;
    short_desc = "Starship wreckage";
    long_desc = "The twisted jagged metal tears at clothes and skin...\n"+
    "There doesn't seem to be any way to get inside except for a\n"+
    "very small opening.  Perhaps one could squeeze in somehow...\n";

    dest_dir = 
    ({
        "players/morgoth/CASTLE/bridge1", "down",
    });
}

init()
{
    ::init();
    add_action("enter_ship", "squeeze");
}

enter_ship()
{
    write("You squeeze through a tiny opening !\n");
    say(call_other(this_player(), "query_name") + " squeezes into the tiny opening.\n");
    call_other(this_player(), "move_player", "squeeze#players/morgoth/CASTLE/bridge3");
    return 1;
}

realm(){return "NT";}
