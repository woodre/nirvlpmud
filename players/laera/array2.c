inv = all_inventory(environment(this_object()));

for (x=0;x<sizeof(rooms);x++)
{
	if(inv[rooms [x]]->id("statue"))
	{
		destruct(this_object());
		move_object(clone_object("/players/jaraxle/monster.c"),environment(this_object()));
	}
}

