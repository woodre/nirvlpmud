id(str) { return str == "orders"; }
short() { return "Some orders"; }
get() { return 1; }

init()
{
	add_action("order_kill_by_name","okbn");
}

order_kill_by_name(arg)
{
	object beano;
	beano = present("xbeano", environment(this_player()));

	if(!beano)
	{
		write("There are no xbeano(V5++) here.\n");
		return 1;
	}

	beano->receive_orders(7, arg);
}