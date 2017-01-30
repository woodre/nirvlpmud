reset(started)
{
    if (!started)
	set_light(1);
}

init()
{
    add_action("north");  add_verb("north");
    add_action("south"); add_verb("south");
    add_action("east");  add_verb("east");
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
    call_other(this_player(), "move_player", "north#room/south/sshore19");
    return 1;
}

south()
{
    call_other(this_player(), "move_player", "south#room/south/sforst32");
    return 1;
}

east()
{
    call_other(this_player(), "move_player", "east#room/south/sshore18");
    return 1;
}
