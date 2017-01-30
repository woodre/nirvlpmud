reset(started)
{
    if (!started)
	set_light(1);
}

init()
{
    add_action("east");	     add_verb("east");
    add_action("southeast"); add_verb("southeast");
}

short()
{
    return "Focus Point";
}

long()
{
    write("You are standing in a small grove on the western most point of the Isle\n" +
	  "of the Magi, Focus Point\n" +
	  "All of the trees here are either diseased, dead or heavily mutated.\n" +
	  "On the very end of the point stands an old, crumbling stone pedestal.\n" +
	  "Legend has it that Arcanarton mounted some sort of a magic focusing device\n"+
	  "here, and used the energy it collected to increase the power of his spells.\n" +
	  "The device is now nowhere to be found.\n" +
	  "The shore of the island continues east and southeast into a\n" +
	  "small grove from here\n" );
}

east()
{
    call_other(this_player(), "move_player", "east#room/south/sislnd11");
    return 1;
}

southeast()
{
     call_other(this_player(), "move_player", "southeast#room/south/sislnd9");
     return 1;
}
