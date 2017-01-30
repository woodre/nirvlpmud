reset(started)
{
    if (!started)
	set_light(1);
}

init()
{
    add_action("south");     add_verb("south");
    add_action("east");      add_verb("east");
    add_action("west");      add_verb("west");
    add_action("northeast"); add_verb("northeast");
}

short()
{
    return "The shore of the Isle of the Magi";
}

long()
{
    write("You are standing on the shore of the Isle of the Magi\n" +
	  "The shore of the island continues northeast to the ruined bridge\n" +
	  "and west into a small grove from here.\n" +
	  "To the south is a old, disused well.\n" +
	  "Standing atop a cliff to the southwest is the ruined tower of Arcanarton,\n" +
	  "but there is no way to get up there from here.\n" +
	  "A path does lead up the hill to the east though.\n");
}

south()
{
     call_other(this_player(), "move_player", "south#room/south/sislnd17");
     return 1;
}

east()
{
     call_other(this_player(), "move_player", "east#room/south/sislnd13");
     return 1;
}

west()
{
     call_other(this_player(), "move_player", "west#room/south/sislnd11");
     return 1;
}

northeast()
{
     call_other(this_player(), "move_player", "northeast#room/south/sislnd1");
     return 1;
}
