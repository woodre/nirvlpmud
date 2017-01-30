reset(started)
{
    if (!started)
	set_light(1);
}

init()
{
    add_action("south"); add_verb("south");
    add_action("east");  add_verb("east");
    add_action("west");  add_verb("west");
}

short()
{
    return "A grove on the shore of the Isle of the Magi";
}

long()
{
    write("You are standing in a grove on the shore of the Isle of the Magi\n" +
	  "All of the trees in the grove are either diseased, dead or heavily mutated.\n" +
	  "The shore of the island continues to the east,and the grove follows\n" +
	  "the shoreline west to Focus Point.\n" +
	  "The grove also continues to the south.\n");
}

south()
{
     call_other(this_player(), "move_player", "south#room/south/sislnd9");
     return 1;
}

east()
{
     call_other(this_player(), "move_player", "east#room/south/sislnd12");
     return 1;
}

west()
{
     call_other(this_player(), "move_player", "west#room/south/sislnd10");
     return 1;
}
