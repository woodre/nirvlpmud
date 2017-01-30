
inherit "room/room";

#define WRITE(x) tell_object(players[j], x)

int players;

init()
{
	::init();
		add_player(this_player());
		set_heart_beat(1);

}


/*
 * Function name: reset
 * Description:   Reset the room
 */
reset(arg) 
{
	if (arg)
		return;
	players = 0;
	set_light(1);
	no_castle_flag = 1;
        short_desc = "Out on the sea";
   long_desc = "A wide open sea stretches out in all directions.  A dense\n"+
               "grayish mist obscures your view of the surroundings. To \n"+
               "the east you can barely see the point where you set off from. \n";
	dest_dir = 0;

}

/*
 * Function name: create_death
 * Description:   Create death.
 */
/*
 * Function name: heart_beat
 * Description:   Let the actions be governed by time.
 */
heart_beat()
{
    
    int align, j, nr;
    
    if (!players)
    {
	set_heart_beat(0);
	return;
    }
    
    nr = sizeof(players);
    
    for (j = 0 ; j < nr ; j += 2)
    {
	
	players[j + 1]++;
	
	if (players[j + 1] == 5)
	{
	    
	    
        WRITE("\nAs you push off from the shore a magical sail appears on\n"+
              "the boat.  You are thrown onto your back as the sail catches\n"+
              "a strong breeze.  You watch the shore speed away.\n\n");
	}
	
	if (players[j + 1] == 10)
	{
	    
        WRITE("\nA crosswind comes along and begins to buffet the boat.  You\n"+
              "find yourself holding on tightly to keep from being thrown \n"+
              "into the icy water.\n\n");
	}
	
	if (players[j + 1] == 15)
	{
	    
        WRITE("\nThe seas start to calm down, so you relax your posture.\n"+
              "You can begin to distinguish the outline of a small isle\n"+
              "to the west.\n\n");
	}
	
	if (players[j + 1] == 20)
	{
	    
        WRITE("The mist becomes so dense you can barely see your hands in\n"+
              "front of your face.  Waves begin to rock the boat back and\n"+
              "forth making you feel nauseous.\n\n");
	}
	
	if (players[j + 1] == 25)
	{
	    
        WRITE("\nThe waves splash hard up against the boat showering you\n"+
              "with icy water.  You bundle up trying to keep the cold out\n\n");
	}
	
	
	if (players[j + 1] == 30)
	{
	    
        WRITE("\nA large rocky shore appears abruptly in front of you.\n"+
              "Unfortunatley you did not have time to maneauver the boat\n"+
              "clear.  The boat hits the rocks with an impact that sends\n"+
              "you flying out of the boat.  Expecting to land in an icy bath\n"+
              "you instead find yourself on a rocky beach.\n\n");
	}
    }
    
    do_remove();
    
}

/*
 * Function name: do_remove
 * Description:   Removes players that's finished
 */
do_remove()
{
	int j, nr;

	if (!players)
		return;

	nr = sizeof(players);

	for (j = 0 ; j < nr ; j += 2)
	{
		if (players[j + 1] == 31)
		{
			move_object(players[j], "/players/molasar/SEA/isle_beach");
			/* Note that move_object() will call exit() */
			/* remove_player(players[j]); */
			do_remove();
			return;
		}
	}
}

/*
 * Function name: remove_death_obj
 * Description:   Remove the "death_mark"-object.
 */
/*
 * Function name: add_player
 * Description:   Adds a player to the list
 */
add_player(plobj)
{

	int i, j, oldlist;

	oldlist = players;

	i = 0;
	if (players)
	{
		i = sizeof(players);
		players = allocate(i + 2);
		for (j = 0 ; j < i ; j ++)
		{
			players[j] = oldlist[j];
		}
	}
	else 
		players = allocate(2);

	players[i] = plobj;
	players[i + 1] = 0;

}

/*
 * Function name: remove_player
 * Description:   Removes a player from the list
 */
remove_player(plobj)
{

	int i, j, x, oldlist;

	if(!players)
		return;

	i = sizeof(players);

	if (i == 2)
	{
		if (players[0] == plobj)
		{
			players = 0;
			set_heart_beat(0);
			return;
		}
		return;
	}

	x = 0;
	oldlist = players;
	players = allocate(i - 2);

	for (j = 0 ; j < i - 2 ; j += 2)
	{

		if (oldlist[j] == plobj)
			x = 2;

		players[j] = oldlist[j + x];
		players[j + 1] = oldlist[j + x + 1];

	}
}

/*
 * Function name: exit
 * Description:   Remove players if they leave the room prematurly
 */
exit(ob)
{

	remove_player(ob);

}

/* 
 * Function name: filter
 * Description:   Filter out relevant commands.
 */

long(str)
{
    int i;
    ::long(str);
    if (str)
	return;
    if (!pointerp(players))
	return;
    for (i=0; i < sizeof(players); i += 2) {
	if (players[i] == this_player()) {
	    if (players[i+1] >= 40 && players[i+1] < 62) {
		write("Lars The Implementor.\n");
		return;
	    }
	}
    }
}
