#define tp this_player()

inherit "obj/quicktyper";
init()
{
	::init();
	add_action("do_commands", "do");
}

short()
{ 
	return owner+"'s hypertyper";
}

query_auto_load()
{
	string temp;
	int i, count;

	i = 0;
	count = 0;
	while(i < sizeof(list_ab)) {
		if(list_ab[i] && list_cmd[i]) {
			count += 1;
		}
		i += 1;
	}
	temp = "/players/sado/ts:" + count + ";";
	i = 0;
	while(i < sizeof(list_ab)) {
		if(list_ab[i] && list_cmd[i]) {
			temp += list_ab[i] + " " + list_cmd[i] + ";.X.Z;";
		}
		i += 1;
	}

	return temp; 
}

do_commands(str)
{
	string *argv, com;
	int i, reps;
	int size;

	argv=explode(str,";");
	size = sizeof(argv);
	for (i = 0; i < size; i++)
	{
		if (sscanf(argv[i], "%d%s", reps, com) == 2)
		{
			while(reps > 0)
			{
				command(com, tp);
				reps--;
			}
		}
		else
		{
			command(argv[i], tp);
		}
	}
	return 1;
}
