reset(started)
{
    if (!started)
	set_light(1);
}

init()
{
    add_action("north");     add_verb("north");
    add_action("south");     add_verb("south");
    add_action("east");      add_verb("east");
    add_action("northwest"); add_verb("northwest");
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
	  "Trails lead into the forest to the north and east.\n" +
	  "The shore of Crescent Lake continues south and northwest\n");
}

north()
{
    call_other(this_player(),"move_player", "north#room/south/sforst8");
    return 1;
}

south()
{
    call_other(this_player(), "move_player", "south#room/south/sshore2");
    return 1;
}

east()
{
    call_other(this_player(),"move_player", "east#room/south/sforst9");
    return 1;
}

northwest()
{
    call_other(this_player(), "move_player", "northwest#room/south/sshore30");
    return 1;
}
