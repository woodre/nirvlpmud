reset(started)
{
    if (!started)
	set_light(1);
}

init()
{
    add_action("north"); add_verb("north");
    add_action("south"); add_verb("south");
    add_action("east");  add_verb("east");
    add_action("west");  add_verb("west");
    add_action("down");  add_verb("down");
}

short()
{
    return "An old disused well";
}

long()
{
    write("You are halfway up the hill.\n" +
	  "An old, disused well stands here, the roof having fallen in from neglect.\n" +
	  "On top of the hill, to the east, stands the ruins of the tower of\n" +
	  "Arcanarton.\n" +
	  "Paths wind down to the shore of the island to the north and south\n" +
	  "Down on the shore to the west is a small grove\n" +
	  "The well has a ladder runing down into it.\n");
}

north()
{
    call_other(this_player(), "move_player", "north#room/south/sislnd12");
    return 1;
}

south()
{
    call_other(this_player(), "move_player", "south#room/south/sislnd8");
    return 1;
}

east()
{
    call_other(this_player(), "move_player", "east#room/south/sislnd18");
    return 1;
}

west()
{
    call_other(this_player(), "move_player", "west#room/south/sislnd9");
    return 1;
}

down()
{
    call_other(this_player(), "move_player", "down the well#room/south/lair");
    return 1;
}
