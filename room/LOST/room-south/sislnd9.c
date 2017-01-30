reset(started)
{
    if (!started)
	set_light(1);
}

init()
{
    add_action("north");     add_verb("north");
    add_action("east");	     add_verb("east");
    add_action("southeast"); add_verb("southeast");
    add_action("northwest"); add_verb("northwest");
}

short()
{
    return "A small grove on the shore of the Isle of the Magi";
}

long()
{
    write("You are standing in a small grove on the shore of the Isle of the Magi\n" +
	  "All of the trees here are either diseased, dead or heavily mutated\n" +
	  "The shoreline continues southeast from here, as well as heading northwest\n" +
	  "to Focus Point.\n" +
	  "The grove continues to the north.\n" +
	  "To the east, you can see an old disused well, and beyond that, on top\n" +
	  "of the hill, stands the ruined tower of Arcanarton\n");
}

north()
{
     call_other(this_player(), "move_player", "north#room/south/sislnd11");
     return 1;
}

east()
{
    call_other(this_player(), "move_player", "east#room/south/sislnd17");
    return 1;
}

southeast()
{
     call_other(this_player(), "move_player", "southeast#room/south/sislnd8");
     return 1;
}

northwest()
{
     call_other(this_player(), "move_player", "northwest#room/south/sislnd10");
     return 1;
}
