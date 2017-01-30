reset(started)
{
    if (!started)
  set_light(1);
}

init()
{
    add_action("north", "north");
    add_action("east", "east");
    add_action("west", "west");
}

short()
{
    return "A dimly lit forest";
}

long()
{
    write("You are in part of a dimly lit forest.\n" +
    "Trails lead north, east and west\n");
}

north()
{
    call_other(this_player(), "move_player", "north#room/south/sforst38");
    return 1;
}

east()
{
    call_other(this_player(), "move_player", "east#room/south/sforst43");
    return 1;
}

west()
{
    call_other(this_player(), "move_player", "west#room/south/sforst45");
    return 1;
}
