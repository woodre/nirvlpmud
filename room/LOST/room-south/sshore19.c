reset(started)
{
    if (!started)
	set_light(1);
}

init()
{
    add_action("north");     add_verb("north");
    add_action("south");     add_verb("south");
    add_action("northeast"); add_verb("northeast");
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
	  "Trails lead into the forest to the north and south.\n" +
	  "The shore of Crescent Lake continues northeast and southeast\n");
}

north()
{
    call_other(this_player(),"move_player", "north#room/south/sforst30");
    return 1;
}

south()
{
    call_other(this_player(), "move_player", "south#room/south/sforst31");
    return 1;
}

northeast()
{
    call_other(this_player(),"move_player", "northeast#room/south/sshore20");
    return 1;
}

southeast()
{
    call_other(this_player(),"move_player", "southeast#room/south/sshore18");
    return 1;
}
