inherit "/obj/treasure.c";
#include <ansi.h>

id(str) {
return str == "stick" || str == "walking_stick";
}

short() { return YEL+"An Old Worn Walking Stick"+NORM; }
long() {
write("This is Master Splinter's old worn out walking stick.\n"+
"It helped him to get along in his old fragile age.\n"+
"It is very old and looks like it has been put to use.\n"+
"If one wanted to they could 'beat <player>' with it as\n"+
"a hilarious emote.\n");
}

drop() { return 0; }
get() { return 1; }
query_weight() { return 2; }
query_value() { return 0; }

init()
{
	add_action("beat", "beat");
}

beat(str)
{
	object player;
	
	if(!str)
	{
		write("Who would you like to beat with the stick?\n");
		return 1;
	}
	
	player = find_player(str);
	
	if(!player)
	{
		write("That player isn't online.\n");
		return 1;
	}
	
	if(player)
	{
		if(present(player, environment(this_player())))
		{
                   tell_object(player, this_player()->query_name()+" walks towards you in an "+BOLD+"aggressive"+NORM+" manner shaking "+this_player()->query_possessive()+YEL+" walking stick"+NORM+"...\n\n                      "+BOLD+"> > >"+HIR+" C R A C K "+NORM+BOLD+"< < <"+NORM+" \n\n"+this_player()->query_name()+" cracks you on top of the head with "+this_player()->query_possessive()+YEL+" walking stick"+NORM+".\n");
			write("You walk towards "+player->query_name()+" in an "+BOLD+"aggressive"+NORM+" manner shaking your "+YEL+"walking stick"+NORM+"...\n\n                      "+BOLD+"> > >"+HIR+" C R A C K "+NORM+BOLD+"< < <"+NORM+" \n\nYou crack "+player->query_name()+" on top of the head with your "+YEL+"walking stick"+NORM+".\n");
			return 1;
		}
		
		if(!present(player, environment(this_player())))
		{
			tell_object(player, this_player()->query_name()+" walks towards you in an "+BOLD+"aggressive"+NORM+" manner shaking "+this_player()->query_possessive()+YEL+" walking stick"+NORM+"...\n\n                      "+BOLD+"> > >"+HIR+" C R A C K "+NORM+BOLD+"< < <"+NORM+" \n\n"+this_player()->query_name()+" cracks you on top of the head with "+this_player()->query_possessive()+YEL+" walking stick"+NORM+". <"+CYN+"From Afar"+NORM+"> \n");
			write("You walk towards "+player->query_name()+" in an "+BOLD+"aggressive"+NORM+" manner shaking your "+YEL+"walking stick"+NORM+"...\n\n                      "+BOLD+"> > >"+HIR+" C R A C K "+NORM+BOLD+"< < <"+NORM+" \n\nYou crack "+player->query_name()+" on top of the head with your "+YEL+"walking stick"+NORM+". <"+CYN+"From Afar"+NORM+"> \n");
			return 1;
		}
		return 1;
	}
	return 1;
}
