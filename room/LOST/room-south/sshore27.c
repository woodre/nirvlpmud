reset(started)
{
    if (!started)
	set_light(1);
}

init()
{
    add_action("north");     add_verb("north");
    add_action("west");      add_verb("west");
    add_action("northeast"); add_verb("northeast");
    add_action("southwest"); add_verb("southwest");
}

short()
{
    return "The shore of Crescent Lake";
}

long()
{
    write("You are standing on the shore of Crescent Lake, a beautiful and\n" +
	  "clear lake. Out in the centre of the lake stands the Isle\n" +
	  "of the Magi.\n" +
	  "Trails lead into the forest to the north and west.\n" +
	  "The shore of Crescent Lake continues northeast and southwest\n");
}

north()
{
    call_other(this_player(), "move_player", "north#room/south/sforst47");
    return 1;
}

west()
{
    call_other(this_player(),"move_player", "west#room/south/sforst46");
    return 1;
}

northeast()
{
    call_other(this_player(),"move_player", "northeast#room/south/sshore28");
    return 1;
}

southwest()
{
    call_other(this_player(),"move_player", "southwest#room/south/sshore26");
    return 1;
}
