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
	  "A trail leads into the forest to the east.\n" +
	  "The shore of Crescent Lake continues north and south\n");
}

north()
{
    call_other(this_player(),"move_player", "north#room/south/sshore5");
    return 1;
}

south()
{
    call_other(this_player(), "move_player", "south#room/south/sshore7");
    return 1;
}

east()
{
    call_other(this_player(),"move_player", "east#room/south/sforst14");
    return 1;
}
