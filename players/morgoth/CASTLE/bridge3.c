inherit "room/room";

reset(arg)
{
    if (arg) return;
    short_desc = "Klezmeer ship";
    long_desc = "This part of the ship used to be the shuttle bay.\n"+
    "Twisted metal and exposed wire are everywhere.\n"+
    " \n"+
    "A panel with a large button is dangling nearby.\n";

    dest_dir = 
    ({
        "players/morgoth/CASTLE/bridge2", "out",
    });
}

init()
{
    ::init();
    add_action("press_button", "push"); /* by verte */
    add_action("press_button", "press");
    add_action("look_button", "look at button");
    add_action("exa_button", "exa button");
}

press_button(str)
{
    if(str == "button");
    {
        write("A hole opens in the fabric of time and you drop in !\n");
        say(call_other(this_player(), "query_name") + "drops through a hole in the fabric of time.\n");
        call_other(this_player(), "move_player", "press#players/morgoth/CASTLE/blue_pub");
        return 1;
    }
    if(!str) return (notify_fail("Push what?\n"), 0); /* verte */
    else return (notify_fail("You may only push the button.\n"), 0); /* verte */
}

look_button()
{
    write("A small red button.\n");
    say(call_other(this_player(), "query_name") + "looks at the button.\n");
    return 1;
}

exa_button()
{
    write("A small red button.\n");
    say(call_other(this_player(), "query_name") + "looks at the button.\n");
    return 1;
}

realm(){return "NT";}