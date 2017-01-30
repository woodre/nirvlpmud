reset(started)
{
    if (!started)
	set_light(1);
}

init()
{
    add_action("northwest"); add_verb("northwest");
    add_action("south");     add_verb("south");
    add_action("west");      add_verb("west");
    add_action("southeast"); add_verb("southeast");
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
	  "Trails lead into the forest to the south and west.\n" +
	  "The shore of Crescent Lake continues northwest and southeast\n");
}

northwest()
{
    call_other(this_player(),"move_player", "northwest#room/south/sshore18");
    return 1;
}

south()
{
    call_other(this_player(), "move_player", "south#room/south/sforst34");
    return 1;
}

southeast()
{
    call_other(this_player(),"move_player", "southeast#room/south/sshore16");
    return 1;
}

west()
{
    call_other(this_player(),"move_player", "west#room/south/sforst33");
    return 1;
}
