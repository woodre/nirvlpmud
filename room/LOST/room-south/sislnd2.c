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
    return "The shore of the Isle of the Magi";
}

long()
{
    write("You are standing on the shore of the Isle of the Magi\n" +
	  "The shore of the island continues east and west from here\n" +
	  "To the south, a hill rises up to the ancient ruins of the Tower\n" +
	  "of Arcanarton, the archmage who used to live on this island\n"); 
}

south()
{
     call_other(this_player(), "move_player", "south#room/south/sislnd14");
     return 1;
}

east()
{
     call_other(this_player(), "move_player", "east#room/south/sislnd3");
     return 1;
}

west()
{
     call_other(this_player(), "move_player", "west#room/south/sislnd1");
     return 1;
}
