
#define DEST "room/forest6"
#include "/obj/ansi.h"

id(str) { return str == "tree"; }

short() 
{
    return ""+HIW+"Fayawyn Tree"+NORM+"";
}

long() 
{
    write("Stretching hundreds of feet tall, this tree is exceptional.\n");
    write("Platforms and bridges can be seen wrapping their way around\n");
    write("the tree making it look like some sort of town or village.\n");
    write("A rope ladder on the east side of the tree looks to be a way\n");
    write("into the village above. Climbing the ladder should do the trick.\n");
}

init() 
{
  add_action("climb", "climb");
}

climb(str) 
{
	
    if(str == "ladder")
    {
	    tell_object(this_player(),
	  			"You climb the ladder into the tree.\n");
			tell_room(environment(this_player()),
				""+this_player()->query_name()+" climbs the ladder into the tree.\n", ({ this_player() }));
    	move_object(this_player(), "/players/cloud/Fayawyn/rooms/fay1.c");
    	command("look", this_player());
    	return 1;
	}
    else
    {
        notify_fail("You can't climb that. Try the ladder.\n");
	}
    	  
}

reset(arg) 
{
    if (arg)
	return;
    move_object(this_object(), DEST);
}

is_castle(){return 1;}

