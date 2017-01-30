id(str)
{
	return str == "detector"; 
}

short()
{
	return "A room detector";
}

get() 
{
	return 1;
}

long()
{
	object room;

	room = environment(this_object());

	if(room)
	{
        write("This is a small, Beano-designed piece of technology which resembles\n"+
              "a green, rubbery hubcap. It is designed to gather more information\n"+
              "about local rooms and such. You just need to drop it in a room, and\n"+
              "then look at the detector for information.\n\n");

		write("The detector is set to '" + room->short() + "'.\n");
		if(room->realm() == "NT") write("This is a no-teleport room.\n");
		if(room->query_no_fight()) write("This is a no-fight room.\n");
	}
}