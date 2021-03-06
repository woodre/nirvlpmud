reset(started)
{
    if (!started)
  set_light(1);
}

init()
{
    add_action("north", "north");
    add_action("south", "south");
    add_action("east", "east");
}

short()
{
    return "A dimly lit forest";
}

long()
{
    write("You are in part of a dimly lit forest.\n" +
    "Trails lead north, south and east\n");
}

north()
{
    call_other(this_player(), "move_player", "north#room/south/sforst6");
    return 1;
}

south()
{
    call_other(this_player(), "move_player", "south#room/south/sforst8");
    return 1;
}

east()
{
    call_other(this_player(), "move_player", "east#room/south/sforst3");
    return 1;
}
