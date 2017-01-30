reset(started)
{
    if (!started)
	set_light(1);
}

init()
{
    add_action("northwest"); add_verb("northwest");
    add_action("west");      add_verb("west");
    add_action("east");      add_verb("east");
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
	  "A trail leads into the forest to the west.\n" +
	  "The shore of Crescent Lake continues northwest and east\n");
}

northwest()
{
    call_other(this_player(),"move_player", "northwest#room/south/sshore15");
    return 1;
}

east()
{
    call_other(this_player(),"move_player", "east#room/south/sshore13");
    return 1;
}

west()
{
    call_other(this_player(), "move_player", "west#room/south/sforst41");
    return 1;
}
