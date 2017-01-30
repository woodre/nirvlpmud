reset(started)
{
    if (!started)
	set_light(1);
}

init()
{
    add_action("north");     add_verb("north");
    add_action("east");      add_verb("east");
    add_action("southeast"); add_verb("southeast");
    add_action("northwest"); add_verb("northwest");
}

short()
{
    return "The shore of the Isle of the Magi";
}

long()
{
    write("You are standing on the shore of the Isle of the Magi\n" +
	  "A path leads up the hill to the east.\n" +
	  "The shore of the island continues southeast and northwest into a\n" +
	  "small grove from here\n" +
	  "To the north, you can see an old disused well.\n");
}

north()
{
     call_other(this_player(), "move_player", "north#room/south/sislnd17");
     return 1;
}

east()
{
     call_other(this_player(), "move_player", "east#room/south/sislnd16");
     return 1;
}

southeast()
{
     call_other(this_player(), "move_player", "southeast#room/south/sislnd7");
     return 1;
}

northwest()
{
     call_other(this_player(), "move_player", "northwest#room/south/sislnd9");
     return 1;
}
