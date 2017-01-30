inherit "/obj/treasure.c";
#include <ansi.h>
int limit;

id(str) {
return str == "dildo";
}

short() { return "A giant dildo"; }

long() {
	write("A sexual device resembling an erect penis in shape, size, and overall appearance.\n");
	write("maybe you can 'throw' the 'dildo at' someone.\n");
}

get() { return 1; }
query_weight() { return 0; }
query_value(){ return 0; }

query_auto_load() {
	return "/players/shinshi/closed/dildo.c:";
}

init()
{
	::init();
	
	add_action("throw", "throw");
}

throw(str)
{
	string who;
	object player, welt;
	
	if(!str)
	{
		write("Usage: throw dildo at <player>'\n");
		return 1;
	}
	
	if(sscanf(str, "dildo at %s", who) != 1)
	{
		return 0;
	}
	
	player = find_living(who);
	
	if(!player)
	{
		write("That person isn't around.\n");
		return 1;
	}
	
	welt = clone_object("/players/shinshi/closed/welt.c");
	
	if(this_player()->query_level() < 20 && player->query_level() > 20)
	{
		if(player->query_real_name() != "shinshi")
		{
			write("Your throw to "+player->query_name()+" fails and the dildo is lost.\n");
			destruct(this_object());
			return 1;
		}
		
		if(player->query_real_name() == "shinshi")
		{
			write("You throw the dildo as hard as you can at "+player->query_name()+".\n");
			write("The dildo smacks "+player->query_name()+" hard across the face leaving\n");
			write("a giant welt in the form of a dick!\n");
			tell_object(player, "You see a giant dildo coming from "+this_player()->query_name()+"'s direction.\n");
			tell_object(player, "It smacks you hard across the face leaving a giant welt in the form of a dick!\n");
			move_object(this_object(), player);
			move_object(welt, player);
			welt->start_it();
			limit++;
			if(limit == 2)
			{
				tell_object(player, "The dildo breaks from the previous hit!\n");
				destruct(this_object());
				return 1;
			}
			return 1;
		}
		return 1;
	}
	
	if(this_player()->query_level() > 20 && player->query_level() > 20)
	{
		write("You throw the dildo as hard as you can at "+player->query_name()+".\n");
		write("The dildo smacks "+player->query_name()+" hard across the face leaving\n");
		write("a giant welt in the form of a dick!\n");
		tell_object(player, "You see a giant dildo coming from "+this_player()->query_name()+"'s direction.\n");
		tell_object(player, "It smacks you hard across the face leaving a giant welt in the form of a dick!\n");
		move_object(this_object(), player);
		move_object(welt, player);
		if(player->query_real_name() != "wicket")
		{
			welt->start_it();
		}
		limit++;
		if(limit == 2)
		{
			tell_object(player, "The dildo breaks from the previous hit!\n");
			destruct(this_object());
			return 1;
		}
		return 1;
	}
	
	if(this_player()->query_level() < 20 && player->query_level() < 20)
	{
		write("You throw the dildo as hard as you can at "+player->query_name()+".\n");
		write("The dildo smacks "+player->query_name()+" hard across the face leaving\n");
		write("a giant welt in the form of a dick!\n");
		tell_object(player, "You see a giant dildo coming from "+this_player()->query_name()+"'s direction.\n");
		tell_object(player, "It smacks you hard across the face leaving a giant welt in the form of a dick!\n");
		move_object(this_object(), player);
		move_object(welt, player);
		limit++;
		if(limit == 2)
		{
			tell_object(player, "The dildo breaks from the previous hit!\n");
			destruct(this_object());
			return 1;
		}
		return 1;
	}
	
	if(this_player()->query_level() > 20 && player->query_level() < 20)
	{
		write("You throw the dildo as hard as you can at "+player->query_name()+".\n");
		write("The dildo smacks "+player->query_name()+" hard across the face leaving\n");
		write("a giant welt in the form of a dick!\n");
		tell_object(player, "You see a giant dildo coming from "+this_player()->query_name()+"'s direction.\n");
		tell_object(player, "It smacks you hard across the face leaving a giant welt in the form of a dick!\n");
		move_object(this_object(), player);
		move_object(welt, player);
		limit++;
		if(limit == 2)
		{
			tell_object(player, "The dildo breaks from the previous hit!\n");
			destruct(this_object());
			return 1;
		}
		return 1;
	}
	return 1;
}
