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
    return "The shore of the Isle of the Magi";
}

long()
{
    write("You are standing on the shore of the Isle of the Magi\n" +
	  "The shore of the island continues northeast and southwest from here\n" +
	  "To the northwest, a hill rises up to the ancient ruins of the Tower\n" +
	  "of Arcanarton, the archmage who used to live on this island\n" +
	  "To the north, you can see some sort of crumbled monument\n"); 
}

north()
{
     call_other(this_player(), "move_player", "north#room/south/sislnd5");
     return 1;
}

west()
{
     call_other(this_player(), "move_player", "west#room/south/sislnd16");
     return 1;
}

northeast()
{
     call_other(this_player(), "move_player", "northeast#room/south/sislnd5");
     return 1;
}

southwest()
{
     call_other(this_player(), "move_player", "southwest#room/south/sislnd7");
     return 1;
}
